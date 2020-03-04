#version 330

out vec4 FragColor;
in vec2 outcol;
void main()
{
        if(outcol.x == 0.0) //check if parameter should draw color (>0) or set black color (<0.1)
            gl_FragColor  = vec4(outcol.x, 0.0, 0.0, 1.0);
        else if(outcol.y / outcol.x < 1.0/3)
            gl_FragColor  = vec4(0.0f, outcol.y * 3, 1.0f, 1.0f);
        else if(outcol.y / outcol.x < 2.0/3)
            gl_FragColor  = vec4((outcol.y - (1.0/3)) * 3, 1.0, 1.0 - (outcol.y - (1.0/3)) * 3, 1.0f);
        else
            gl_FragColor  = vec4(1.0f, 1.0 - (outcol.y - (2.0/3)) * 3, 0.0f, 1.0f);
} 
