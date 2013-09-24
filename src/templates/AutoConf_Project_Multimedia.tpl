>AutoConf_Project_Multimedia<-
>0.1.0<-
>GPL v2<-
>Development/Tools<-
>MagicLinux<-
>mkdir -p $RPM_BUILD_ROOT/opt/kde3/bin
mkdir -p $RPM_BUILD_ROOT/usr/share/applications
./configure --prefix=/opt/kde3
CFLAGS="$RPM_OPT_FLAGS" CXXFLAGS="$RPM_OPT_FLAGS" \
make<-
>cp src/myApplication $RPM_BUILD_ROOT/opt/kde3/bin
<-
