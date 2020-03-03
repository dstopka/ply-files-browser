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
        else if(outcol.y / outcol.x < 3.0/3)
            gl_FragColor  = vec4(1.0f, 1.0 - (outcol.y - (1.0/3)) * 3, 0.0f, 1.0f);
        /*else if(outcol.y/outcol.x < 1.0/5) //rainbow colouring
            gl_FragColor  = vec4(1-outcol.y/outcol.x*5, 0.0f, 1.0f, 1.0f);
        else if(outcol.y/outcol.x < 2.f/5)
            gl_FragColor  = vec4(0.0, (outcol.y/outcol.x-1.0/5)*5, 1.0, 1.0);
        else if(outcol.y/outcol.x < 3.f/5)
            gl_FragColor  = vec4(0.0, 1, 1-(outcol.y/outcol.x-2.0/5)*5, 1.0);
        else if(outcol.y/outcol.x < 4.f/5)
            gl_FragColor  = vec4((outcol.y/outcol.x-3.0/5)*5, 1.0, 0.0, 1.0);
        else if(outcol.y/outcol.x <= 1.1f)
            gl_FragColor  = vec4(1.0, 1-(outcol.y/outcol.x-4.0/5)*5, 0.0, 1.0);
        else
            gl_FragColor  = vec4(1.0, 1.0, 1.0, 1.0);*/
} 
