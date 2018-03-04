 POINT mousePos;
        GetCursorPos(&mousePos);
        ScreenToClient( this->GetWindowHWND(), &mousePos );         

        CMatrix4x4 matProjection = m_pCamera->getViewMatrix() *  m_pCamera->getProjectionMatrix() ;

        CMatrix4x4 matInverse =  matProjection.inverse();


        float in[4];
        float winZ = 1.0;


        in[0]=(2.0f*((float)(mousePos.x-0)/(this->GetResolution().x-0)))-1.0f,
        in[1]=1.0f-(2.0f*((float)(mousePos.y-0)/(this->GetResolution().y-0)));
        in[2]=2.0* winZ -1.0;
        in[3]=1.0;          

        CVector4 vIn = CVector4(in[0],in[1],in[2],in[3]);
        pos = vIn * matInverse;

        pos.w = 1.0 / pos.w;

        pos.x *= pos.w;
        pos.y *= pos.w;
        pos.z *= pos.w;



        sprintf(strTitle,"%f %f %f / %f,%f,%f ",m_pCamera->m_vPosition.x,m_pCamera->m_vPosition.y,m_pCamera->m_vPosition.z,pos.x,pos.y,pos.z);

        SetWindowText(this->GetWindowHWND(),strTitle);