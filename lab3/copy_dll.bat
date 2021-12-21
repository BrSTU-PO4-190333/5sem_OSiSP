@REM Копируем *.exe файл
@REM copy build-gpi_osisp5_lab3-Desktop_Qt_6_2_2_MinGW_64_bit-Debug\gpi_osisp5_option5\debug\gpi_osisp5_option5.exe gpi_app
@REM copy build-gpi_osisp5_lab3-Desktop_Qt_6_2_2_MinGW_64_bit-Release\gpi_osisp5_option5\release\gpi_osisp5_option5.exe gpi_app

@REM Копируем основные dll
@REM copy C:\gpi_apps\Qt\6.2.2\mingw_64\bin\Qt6Widgets.dll gpi_app
@REM copy C:\gpi_apps\Qt\6.2.2\mingw_64\bin\Qt6Gui.dll gpi_app
@REM copy C:\gpi_apps\Qt\6.2.2\mingw_64\bin\Qt6Core.dll gpi_app
@REM copy C:\gpi_apps\Qt\6.2.2\mingw_64\bin\libgcc_s_seh-1.dll gpi_app
@REM Этот libstdc++-6.dll лучше скопировать вручную 
@REM copy C:\gpi_apps\Qt\6.2.2\mingw_64\bin\libstdc++-6.dll gpi_app
@REM copy C:\gpi_apps\Qt\6.2.2\mingw_64\bin\libwinpthread-1.dll gpi_app

@REM Копируем helper.dll
copy build-gpi_osisp5_lab3-Desktop_Qt_6_2_2_MinGW_64_bit-Debug\gpi_helper\debug\gpi_helper.dll build-gpi_osisp5_lab3-Desktop_Qt_6_2_2_MinGW_64_bit-Debug\gpi_osisp5_option5\debug\
copy build-gpi_osisp5_lab3-Desktop_Qt_6_2_2_MinGW_64_bit-Release\gpi_helper\release\gpi_helper.dll build-gpi_osisp5_lab3-Desktop_Qt_6_2_2_MinGW_64_bit-Release\gpi_osisp5_option5\release\
