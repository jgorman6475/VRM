for /F "Tokens=2* skip=2" %%A In ('REG QUERY "HKEY_CURRENT_USER\SOFTWARE\Bohemia Interactive\imagetopaa" /v "Tool"') DO SET ImageToPAAPath=%%B

rem satellite texture
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\s_00?_???_lco.png
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\s_01?_???_lco.png
START "" /D"%CD%" /B /WAIT "%ImageToPAAPath%" layers\s_02?_???_lco.png
 
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\s_03?_???_lco.png
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\s_04?_???_lco.png
START "" /D"%CD%" /B /WAIT "%ImageToPAAPath%" layers\s_05?_???_lco.png
 
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\s_06?_???_lco.png
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\s_07?_???_lco.png
START "" /D"%CD%" /B /WAIT "%ImageToPAAPath%" layers\s_08?_???_lco.png
 
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\s_09?_???_lco.png
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\s_10?_???_lco.png
START "" /D"%CD%" /B /WAIT "%ImageToPAAPath%" layers\s_11?_???_lco.png
 
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\s_12?_???_lco.png
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\s_13?_???_lco.png

rem mask - quick, as they are simple images with few colors
START "" /D"%CD%" /B /WAIT "%ImageToPAAPath%" layers\m_00?_???_lca.png
 
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\m_01?_???_lca.png
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\m_02?_???_lca.png
START "" /D"%CD%" /B /WAIT "%ImageToPAAPath%" layers\m_03?_???_lca.png
 
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\m_04?_???_lca.png
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\m_05?_???_lca.png
START "" /D"%CD%" /B /WAIT "%ImageToPAAPath%" layers\m_06?_???_lca.png
 
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\m_07?_???_lca.png
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\m_08?_???_lca.png
START "" /D"%CD%" /B /WAIT "%ImageToPAAPath%" layers\m_09?_???_lca.png
 
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\m_10?_???_lca.png
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\m_11?_???_lca.png
START "" /D"%CD%" /B /WAIT "%ImageToPAAPath%" layers\m_12?_???_lca.png
 
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\m_13?_???_lca.png

rem normal map - if you dont use it no problem, its just skipped
START "" /D"%CD%" /B /WAIT "%ImageToPAAPath%" layers\n_00?_???_nohq.png
 
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\n_01?_???_nohq.png
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\n_02?_???_nohq.png
START "" /D"%CD%" /B /WAIT "%ImageToPAAPath%" layers\n_03?_???_nohq.png
 
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\n_04?_???_nohq.png
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\n_05?_???_nohq.png
START "" /D"%CD%" /B /WAIT "%ImageToPAAPath%" layers\n_06?_???_nohq.png
 
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\n_07?_???_nohq.png
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\n_08?_???_nohq.png
START "" /D"%CD%" /B /WAIT "%ImageToPAAPath%" layers\n_09?_???_nohq.png
 
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\n_10?_???_nohq.png
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\n_11?_???_nohq.png
START "" /D"%CD%" /B /WAIT "%ImageToPAAPath%" layers\n_12?_???_nohq.png
 
START "" /D"%CD%" /B "%ImageToPAAPath%" layers\n_13?_???_nohq.png