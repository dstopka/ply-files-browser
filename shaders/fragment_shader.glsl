#version 330

out vec4 FragColor;
in vec3 outcol;
void main()
{
        if(outcol.x < -.1f) //check if parameter should draw color (>0) or set black color (<0.1)
            gl_FragColor  = vec4(0.0f, 0.0f, 0.0f, 1.0f);
        else if(outcol.y/outcol.x < 1.f/5) //rainbow colouring
            gl_FragColor  = vec4(1-outcol.y/outcol.x*5, 0.0f, 1.0f, 1.0f);
        else if(outcol.y/outcol.x < 2.f/5)
            gl_FragColor  = vec4(0.0f, (outcol.y/outcol.x-1f/5)*5, 1.0f, 1.0f);
        else if(outcol.y/outcol.x < 3.f/5)
            gl_FragColor  = vec4(0.0f, 1, 1-(outcol.y/outcol.x-2f/5)*5, 1.0f);
        else if(outcol.y/outcol.x < 4.f/5)
            gl_FragColor  = vec4((outcol.y/outcol.x-3f/5)*5, 1.0f, 0.0f, 1.0f);
        else if(outcol.y/outcol.x <= 1.1f)
            gl_FragColor  = vec4(1.0f, 1-(outcol.y/outcol.x-4f/5)*5, 0.0f, 1.0f);
        else
            gl_FragColor  = vec4(1, 1, 1, 1.0f);
} 
