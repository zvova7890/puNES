{
"#pragma parameter CRTgamma \"CRTGeom Target Gamma\" 2.4 0.1 5.0 0.1\n"
"#pragma parameter monitorgamma \"CRTGeom Monitor Gamma\" 2.2 0.1 5.0 0.1\n"
"#pragma parameter d \"CRTGeom Distance\" 1.5 0.1 3.0 0.1\n"
"#pragma parameter CURVATURE \"CRTGeom Curvature Toggle\" 1.0 0.0 1.0 1.0\n"
"#pragma parameter R \"CRTGeom Curvature Radius\" 2.0 0.1 10.0 0.1\n"
"#pragma parameter cornersize \"CRTGeom Corner Size\" 0.03 0.001 1.0 0.005\n"
"#pragma parameter cornersmooth \"CRTGeom Corner Smoothness\" 1000.0 80.0 2000.0 100.0\n"
"#pragma parameter x_tilt \"CRTGeom Horizontal Tilt\" 0.0 -0.5 0.5 0.05\n"
"#pragma parameter y_tilt \"CRTGeom Vertical Tilt\" 0.0 -0.5 0.5 0.05\n"
"#pragma parameter overscan_x \"CRTGeom Horiz. Overscan %\" 100.0 -125.0 125.0 1.0\n"
"#pragma parameter overscan_y \"CRTGeom Vert. Overscan %\" 100.0 -125.0 125.0 1.0\n"
"#pragma parameter DOTMASK \"CRTGeom Dot Mask Toggle\" 0.3 0.0 0.3 0.3\n"
"#pragma parameter SHARPER \"CRTGeom Sharpness\" 1.0 1.0 3.0 1.0\n"
"#pragma parameter scanline_weight \"CRTGeom Scanline Weight\" 0.3 0.1 0.5 0.01\n"
"#pragma parameter lum \"CRTGeom Luminance Boost\" 0.0 0.0 1.0 0.01\n"
"#pragma parameter interlace_toggle \"CRTGeom Interlacing\" 0.0 0.0 1.0 1.0\n"
"\n"
"#ifdef PARAMETER_UNIFORM\n"
"uniform float CRTgamma;\n"
"uniform float monitorgamma;\n"
"uniform float d;\n"
"uniform float CURVATURE;\n"
"uniform float R;\n"
"uniform float cornersize;\n"
"uniform float cornersmooth;\n"
"uniform float x_tilt;\n"
"uniform float y_tilt;\n"
"uniform float overscan_x;\n"
"uniform float overscan_y;\n"
"uniform float DOTMASK;\n"
"uniform float SHARPER;\n"
"uniform float scanline_weight;\n"
"uniform float lum;\n"
"uniform float interlace_toggle;\n"
"\n"
"#else\n"
"#define CRTgamma 2.4\n"
"#define monitorgamma 2.2\n"
"#define d 1.5\n"
"#define CURVATURE 1.0\n"
"#define R 2.0\n"
"#define cornersize 0.03\n"
"#define cornersmooth 1000.0\n"
"#define x_tilt 0.0\n"
"#define y_tilt 0.0\n"
"#define overscan_x 100.0\n"
"#define overscan_y 100.0\n"
"#define DOTMASK 0.3\n"
"#define SHARPER 1.0\n"
"#define scanline_weight 0.3\n"
"#define lum 0.0\n"
"#define interlace_toggle 1.0\n"
"\n"
"#endif\n"
"// END PARAMETERS //\n"
"\n"
"/* COMPATIBILITY\n"
"   - HLSL compilers\n"
"   - Cg   compilers\n"
"   - FX11 compilers\n"
"*/\n"
"\n"
"#define mod(x,y) (x - y * trunc(x/y))\n"
"\n"
"/*\n"
"    CRT-interlaced\n"
"\n"
"    Copyright (C) 2010-2012 cgwg, Themaister and DOLLS\n"
"\n"
"    This program is free software; you can redistribute it and/or modify it\n"
"    under the terms of the GNU General Public License as published by the Free\n"
"    Software Foundation; either version 2 of the License, or (at your option)\n"
"    any later version.\n"
"\n"
"    (cgwg gave their consent to have the original version of this shader\n"
"    distributed under the GPL in this message:\n"
"\n"
"        http://board.byuu.org/viewtopic.php?p=26075#p26075\n"
"\n"
"        \"Feel free to distribute my shaders under the GPL. After all, the\n"
"        barrel distortion code was taken from the Curvature shader, which is\n"
"        under the GPL.\"\n"
"    )\n"
"	This shader variant is pre-configured with screen curvature\n"
"*/\n"
"\n"
#include "../compat_includes.inc"
"uniform COMPAT_Texture2D(decal) : TEXUNIT0;\n"
"uniform float4x4 modelViewProj;\n"
"\n"
"        // Comment the next line to disable interpolation in linear gamma (and\n"
"        // gain speed).\n"
"        #define LINEAR_PROCESSING\n"
"\n"
"        // Enable 3x oversampling of the beam profile; improves moire effect caused by scanlines+curvature\n"
"        #define OVERSAMPLE\n"
"\n"
"        // Use the older, purely gaussian beam profile; uncomment for speed\n"
"        //#define USEGAUSSIAN\n"
"      \n"
"        // Use interlacing detection; may interfere with other shaders if combined\n"
"        #define INTERLACED\n"
"	  \n"
"	    // Enable Dot-mask emulation:\n"
"        // Output pixels are alternately tinted green and magenta.\n"
"//        #define DOTMASK\n"
"\n"
"        // Macros.\n"
"        #define FIX(c) max(abs(c), 1e-5);\n"
"        #define PI 3.141592653589\n"
"\n"
"        #ifdef LINEAR_PROCESSING\n"
"        #       define TEX2D(c) pow(COMPAT_SamplePoint(s0, (c)), float4(CRTgamma,CRTgamma,CRTgamma,CRTgamma))\n"
"        #else\n"
"        #       define TEX2D(c) COMPAT_SamplePoint(s0, (c))\n"
"        #endif\n"
"\n"
"        // aspect ratio\n"
"        static float2 aspect = float2(1.0, 0.75);\n"
"\n"
"\n"
"        float intersect(float2 xy, float4 sin_cos_angle)\n"
"        {\n"
"                float A = dot(xy,xy)+d*d;\n"
"                float B = 2.0*(R*(dot(xy,sin_cos_angle.xy)-d*sin_cos_angle.zw.x*sin_cos_angle.zw.y)-d*d);\n"
"                float C = d*d + 2.0*R*d*sin_cos_angle.zw.x*sin_cos_angle.zw.y;\n"
"                return (-B-sqrt(B*B-4.0*A*C))/(2.0*A);\n"
"        }\n"
"\n"
"        float2 bkwtrans(float2 xy, float4 sin_cos_angle)\n"
"        {\n"
"                float c = intersect(xy, sin_cos_angle);\n"
"                float2 point_ = float2(c,c)*xy;\n"
"                point_ -= float2(-R,-R)*sin_cos_angle.xy;\n"
"                point_ /= float2(R,R);\n"
"                float2 tang = sin_cos_angle.xy/sin_cos_angle.zw;\n"
"                float2 poc = point_/sin_cos_angle.zw;\n"
"                float A = dot(tang,tang)+1.0;\n"
"                float B = -2.0*dot(poc,tang);\n"
"                float C = dot(poc,poc)-1.0;\n"
"                float a = (-B+sqrt(B*B-4.0*A*C))/(2.0*A);\n"
"                float2 uv = (point_-a*sin_cos_angle.xy)/sin_cos_angle.zw;\n"
"                float r = FIX(R*acos(a));\n"
"                return uv*r/sin(r/R);\n"
"        }\n"
"\n"
"        float2 fwtrans(float2 uv, float4 sin_cos_angle)\n"
"        {\n"
"                float r = FIX(sqrt(dot(uv,uv)));\n"
"                uv *= sin(r/R)/r;\n"
"                float x = 1.0-cos(r/R);\n"
"                float D = d/R + x*sin_cos_angle.z*sin_cos_angle.w+dot(uv,sin_cos_angle.xy);\n"
"                return d*(uv*sin_cos_angle.zw-x*sin_cos_angle.xy)/D;\n"
"        }\n"
"\n"
"        float3 maxscale(float4 sin_cos_angle)\n"
"        {\n"
"                float2 c = bkwtrans(-R * sin_cos_angle.xy / (1.0 + R/d*sin_cos_angle.z*sin_cos_angle.w), sin_cos_angle);\n"
"                float2 a = float2(0.5,0.5)*aspect;\n"
"                float2 lo = float2(fwtrans(float2(-a.x,c.y), sin_cos_angle).x,\n"
"                             fwtrans(float2(c.x,-a.y), sin_cos_angle).y)/aspect;\n"
"                float2 hi = float2(fwtrans(float2(+a.x,c.y), sin_cos_angle).x,\n"
"                             fwtrans(float2(c.x,+a.y), sin_cos_angle).y)/aspect;\n"
"                return float3((hi+lo)*aspect*0.5,max(hi.x-lo.x,hi.y-lo.y));\n"
"        }\n"
"\n"
"        // Calculate the influence of a scanline on the current pixel.\n"
"        //\n"
"        // 'distance' is the distance in texture coordinates from the current\n"
"        // pixel to the scanline in question.\n"
"        // 'color' is the colour of the scanline at the horizontal location of\n"
"        // the current pixel.\n"
"        float4 scanlineWeights(float distance, float4 color)\n"
"        {\n"
"                // \"wid\" controls the width of the scanline beam, for each RGB\n"
"                // channel The \"weights\" lines basically specify the formula\n"
"                // that gives you the profile of the beam, i.e. the intensity as\n"
"                // a function of distance from the vertical center of the\n"
"                // scanline. In this case, it is gaussian if width=2, and\n"
"                // becomes nongaussian for larger widths. Ideally this should\n"
"                // be normalized so that the integral across the beam is\n"
"                // independent of its width. That is, for a narrower beam\n"
"                // \"weights\" should have a higher peak at the center of the\n"
"                // scanline than for a wider beam.\n"
"        #ifdef USEGAUSSIAN\n"
"                float4 wid = 0.3 + 0.1 * pow(color, float4(3.0, 3.0, 3.0, 3.0));\n"
"                float v = distance / (wid * scanline_weight/0.3);\n"
"                float4 weights = float4(v,v,v,v);\n"
"                return (lum + 0.4) * exp(-weights * weights) / wid;\n"
"        #else\n"
"                float4 wid = 2.0 + 2.0 * pow(color, float4(4.0, 4.0, 4.0, 4.0));\n"
"                float v = distance / scanline_weight;\n"
"                float4 weights = float4(v,v,v,v);\n"
"                return (lum + 1.4) * exp(-pow(weights * rsqrt(0.5 * wid), wid)) / (0.6 + 0.2 * wid);\n"
"        #endif\n"
"        }\n"
"\n"
"struct out_vertex {\n"
"	float4 position : COMPAT_POS;\n"
"	float2 texCoord : TEXCOORD0;\n"
"#ifdef HLSL_4\n"
"	float2 one : VAR0;\n"
"	float  mod_factor : VAR1;\n"
"	float2 ilfac : VAR2;\n"
"	float3 stretch : VAR3;\n"
"	float4 sin_cos_angle : VAR4;\n"
"	float2 TextureSize : VAR5;\n"
"#else\n"
"	float2 one;\n"
"	float  mod_factor;\n"
"	float2 ilfac;\n"
"	float3 stretch;\n"
"	float4 sin_cos_angle;\n"
"	float2 TextureSize;\n"
"	float4 Color    : COLOR;\n"
"#endif\n"
"};\n"
"\n"
"\n"
"/* VERTEX_SHADER */\n"
"out_vertex main_vertex(COMPAT_IN_VERTEX)\n"
"{\n"
"	out_vertex OUT;\n"
"#ifdef HLSL_4\n"
"	float4 position = VIN.position;\n"
"	float2 texCoord = VIN.texCoord;\n"
"#else\n"
"	OUT.Color = color;\n"
"#endif\n"
"\n"
"    OUT.position = mul(modelViewProj, position);\n"
"\n"
"    // Precalculate a bunch of useful values we'll need in the fragment\n"
"    // shader.\n"
"    float2 sinangle = sin(float2(x_tilt, y_tilt));\n"
"    float2 cosangle = cos(float2(x_tilt, y_tilt));\n"
"    OUT.sin_cos_angle = float4(sinangle.x, sinangle.y, cosangle.x, cosangle.y);\n"
"    OUT.stretch = maxscale(OUT.sin_cos_angle);\n"
"	OUT.texCoord = texCoord;\n"
"    OUT.TextureSize = float2(SHARPER * COMPAT_texture_size.x, COMPAT_texture_size.y);\n"
"\n"
"    OUT.ilfac = float2(1.0,clamp(floor(COMPAT_video_size.y/(200.0 * (1.0 - interlace_toggle))),1.0,2.0));\n"
"\n"
"    // The size of one texel, in texture-coordinates.\n"
"    OUT.one = OUT.ilfac / OUT.TextureSize;\n"
"\n"
"    // Resulting X pixel-coordinate of the pixel we're drawing.\n"
"    OUT.mod_factor = texCoord.x * COMPAT_texture_size.x * COMPAT_output_size.x / COMPAT_video_size.x;\n"
"    return OUT;\n"
"}\n"
"\n"
"/* FRAGMENT SHADER */\n"
"float4 crt_geom(float2 texture_size, float2 video_size, float2 output_size, float frame_count, float4 sin_cos_angle, float3 stretch,\n"
"	float2 ilfac, float2 one, float mod_factor, float2 TextureSize, float2 texCoord, COMPAT_Texture2D(s0))\n"
"{\n"
"                // Here's a helpful diagram to keep in mind while trying to\n"
"                // understand the code:\n"
"                //\n"
"                //  |      |      |      |      |\n"
"                // -------------------------------\n"
"                //  |      |      |      |      |\n"
"                //  |  01  |  11  |  21  |  31  | <-- current scanline\n"
"                //  |      | @    |      |      |\n"
"                // -------------------------------\n"
"                //  |      |      |      |      |\n"
"                //  |  02  |  12  |  22  |  32  | <-- next scanline\n"
"                //  |      |      |      |      |\n"
"                // -------------------------------\n"
"                //  |      |      |      |      |\n"
"                //\n"
"                // Each character-cell represents a pixel on the output\n"
"                // surface, \"@\" represents the current pixel (always somewhere\n"
"                // in the bottom half of the current scan-line, or the top-half\n"
"                // of the next scanline). The grid of lines represents the\n"
"                // edges of the texels of the underlying texture.\n"
"\n"
"                // Texture coordinates of the texel containing the active pixel.\n"
"	float2 xy = 0.0;\n"
"      if (CURVATURE > 0.5)\n"
"                {\n"
"                float2 cd = texCoord;\n"
"                cd *= texture_size / video_size;\n"
"                cd = (cd-float2(0.5, 0.5))*aspect*stretch.z+stretch.xy;\n"
"                xy =  (bkwtrans(cd, sin_cos_angle)/float2(overscan_x / 100.0, overscan_y / 100.0)/aspect+float2(0.5, 0.5)) * video_size / texture_size;\n"
"		}\n"
"      else\n"
"               {\n"
"                xy = texCoord;\n"
"		}\n"
"\n"
"                float2 cd2 = xy;\n"
"                cd2 *= texture_size / video_size;\n"
"                cd2 = (cd2 - float2(0.5, 0.5)) * float2(overscan_x / 100.0, overscan_y / 100.0) + float2(0.5, 0.5);\n"
"                cd2 = min(cd2, float2(1.0, 1.0)-cd2) * aspect;\n"
"                float2 cdist = float2(cornersize, cornersize);\n"
"                cd2 = (cdist - min(cd2,cdist));\n"
"                float dist = sqrt(dot(cd2,cd2));\n"
"                float cval = clamp((cdist.x-dist)*cornersmooth,0.0, 1.0);\n"
"\n"
"                float2 xy2 = ((xy*TextureSize/video_size-float2(0.5, 0.5))*float2(1.0,1.0)+float2(0.5, 0.5))*video_size/TextureSize;\n"
"                // Of all the pixels that are mapped onto the texel we are\n"
"                // currently rendering, which pixel are we currently rendering?\n"
"                float2 ilfloat = float2(0.0,ilfac.y > 1.5 ? mod(float(frame_count),2.0) : 0.0);\n"
"\n"
"            float2 ratio_scale = (xy * TextureSize - float2(0.5,0.5) + ilfloat)/ilfac;\n"
"      \n"
"      #ifdef OVERSAMPLE\n"
"                float filter = video_size.y / output_size.y;\n"
"      #endif\n"
"                float2 uv_ratio = frac(ratio_scale);\n"
"\n"
"                // Snap to the center of the underlying texel.\n"
"\n"
"            xy = (floor(ratio_scale)*ilfac + float2(0.5, 0.5) - ilfloat) / TextureSize;\n"
"\n"
"                // Calculate Lanczos scaling coefficients describing the effect\n"
"                // of various neighbour texels in a scanline on the current\n"
"                // pixel.\n"
"                float4 coeffs = PI * float4(1.0 + uv_ratio.x, uv_ratio.x, 1.0 - uv_ratio.x, 2.0 - uv_ratio.x);\n"
"\n"
"                // Prevent division by zero.\n"
"                coeffs = FIX(coeffs);\n"
"\n"
"                // Lanczos2 kernel.\n"
"                coeffs = 2.0 * sin(coeffs) * sin(coeffs / 2.0) / (coeffs * coeffs);\n"
"\n"
"                // Normalize.\n"
"                coeffs /= dot(coeffs, float4(1.0, 1.0, 1.0, 1.0));\n"
"\n"
"                // Calculate the effective colour of the current and next\n"
"                // scanlines at the horizontal location of the current pixel,\n"
"                // using the Lanczos coefficients above.\n"
"    float4 col  = clamp(mul(coeffs, float4x4(\n"
"                    TEX2D(xy + float2(-one.x, 0.0)),\n"
"                    TEX2D(xy),\n"
"                    TEX2D(xy + float2(one.x, 0.0)),\n"
"                    TEX2D(xy + float2(2.0 * one.x, 0.0)))),\n"
"            0.0, 1.0);\n"
"    float4 col2 = clamp(mul(coeffs, float4x4(\n"
"                    TEX2D(xy + float2(-one.x, one.y)),\n"
"                    TEX2D(xy + float2(0.0, one.y)),\n"
"                    TEX2D(xy + one),\n"
"                    TEX2D(xy + float2(2.0 * one.x, one.y)))),\n"
"            0.0, 1.0);\n"
"\n"
"        #ifndef LINEAR_PROCESSING\n"
"                col  = pow(col , float4(CRTgamma));\n"
"                col2 = pow(col2, float4(CRTgamma));\n"
"        #endif\n"
"\n"
"                // Calculate the influence of the current and next scanlines on\n"
"                // the current pixel.\n"
"                float4 weights  = scanlineWeights(uv_ratio.y, col);\n"
"                float4 weights2 = scanlineWeights(1.0 - uv_ratio.y, col2);\n"
"        #ifdef OVERSAMPLE\n"
"                uv_ratio.y =uv_ratio.y+1.0/3.0*filter;\n"
"                weights = (weights+scanlineWeights(uv_ratio.y, col))/3.0;\n"
"                weights2=(weights2+scanlineWeights(abs(1.0-uv_ratio.y), col2))/3.0;\n"
"                uv_ratio.y =uv_ratio.y-2.0/3.0*filter;\n"
"                weights=weights+scanlineWeights(abs(uv_ratio.y), col)/3.0;\n"
"                weights2=weights2+scanlineWeights(abs(1.0-uv_ratio.y), col2)/3.0;\n"
"        #endif\n"
"                float3 mul_res  = (col * weights + col2 * weights2).rgb;\n"
"                mul_res *= float3(cval, cval, cval);\n"
"\n"
"                // dot-mask emulation:\n"
"                // Output pixels are alternately tinted green and magenta.\n"
"                float3 dotMaskWeights = lerp(\n"
"                        float3(1.0, 1.0 - DOTMASK, 1.0),\n"
"                        float3(1.0 - DOTMASK, 1.0, 1.0 - DOTMASK),\n"
"                        floor(mod(mod_factor, 2.0))\n"
"                    ); \n"
"		mul_res *= dotMaskWeights;\n"
"        \n"
"		\n"
"                // Convert the image gamma for display on our output device.\n"
"                mul_res = pow(mul_res, float3(1.0 / monitorgamma, 1.0 / monitorgamma, 1.0 / monitorgamma));\n"
"\n"
"                // Color the texel.\n"
"                return float4(mul_res, 1.0);\n"
"}\n"
"\n"
"float4 main_fragment(COMPAT_IN_FRAGMENT) : COMPAT_Output\n"
"{\n"
"	return crt_geom(COMPAT_texture_size, COMPAT_video_size, COMPAT_output_size, COMPAT_frame_count, VOUT.sin_cos_angle, VOUT.stretch,\n"
"	VOUT.ilfac, VOUT.one, VOUT.mod_factor, VOUT.TextureSize, VOUT.texCoord, decal);\n"
"}\n"
"COMPAT_END\n"
},
