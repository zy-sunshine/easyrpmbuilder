>QMake_Project_Development<-
>0.1.0<-
>GPL v2<-
>Development/Tools<-
>MagicLinux<-
>mkdir -p %{buildroot}%{_bindir}
mkdir -p %{buildroot}%{_datadir}/%{name}
mkdir -p %{buildroot}%{_datadir}/qt4/translations
mkdir -p %{buildroot}%{_datadir}/doc/packages/%{name}
mkdir -p %{buildroot}%{_datadir}/applications
qmake
CFLAGS="$RPM_OPT_FLAGS" CXXFLAGS="$RPM_OPT_FLAGS" \
make
lrelease %{name}.pro<-
>cp bin/* %{buildroot}%{_bindir}
cp -r doc/* %{buildroot}%{_datadir}/doc/packages/%{name}
cp src/translations/english.qm %{buildroot}%{_datadir}/qt4/translations/%{name}_en_GB.qm
cp src/translations/german.qm %{buildroot}%{_datadir}/qt4/translations/%{name}_de_DE.qm
cp src/icons/%{name}.png %{buildroot}%{_datadir}/%{name}/<-
