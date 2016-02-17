Shader "PhysiologyEngine/TraceShader"
{
    SubShader
    {
    	ZWrite Off
		Blend SrcAlpha OneMinusSrcAlpha 
	
        Pass
        {
         CGPROGRAM
         #pragma vertex vert
         #pragma fragment frag
         #include "UnityCG.cginc"
 
         struct v2f {
             float4 pos : SV_POSITION;
             float4 color : COLOR;
         };
 
         v2f vert (appdata_full v)
         {
             v2f o;
             o.pos = mul (UNITY_MATRIX_MVP, v.vertex);
             o.color = v.color;
             return o;
         }
 
         half4 frag (v2f i) : COLOR
         {
             return half4 (i.color);
         }
         ENDCG
        }
    }
    Fallback "Diffuse"
}