#!/bin/bash

# root check
if [ `whoami` != "root" ];
then
    echo "You have to be root to run this script ....";
    exit -1;
fi;
echo "***********************************************"
echo "*                                             *"
echo "* clean up .....................              *"
echo "*                                             *"
echo "***********************************************"
make clean 2>/dev/null
make distclean 2>/dev/null
echo "***********************************************"
echo "*                                             *"
echo "* compiling ....................              *"
echo "*                                             *"
echo "***********************************************"
qmake
make
echo "***********************************************"
echo "*                                             *"
echo "* translation ..................              *"
echo "*                                             *"
echo "***********************************************"
lrelease easyrpmbuilder.pro
echo "***********************************************"
echo "*                                             *"
echo "* installing ...................              *"
echo "*                                             *"
echo "***********************************************"
if [ ! -e /usr/share/doc/packages/easyrpmbuilder ];
then
    mkdir -p /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO
fi
if [ ! -e /usr/share/easyrpmbuilder ];
then
    mkdir -p /usr/share/easyrpmbuilder
fi
if [ ! -e /usr/share/qt4/translations ];
then
    mkdir -p /usr/share/qt4/translations
fi

echo "cp -r doc/RPM-HOWTO/* /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO" && cp -r doc/RPM-HOWTO/* /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO
echo "cp -r src/templates/*.tpl /usr/share/easyrpmbuilder" && cp -r src/templates/*.tpl /usr/share/easyrpmbuilder
echo "cp -r src/groups/*.grp /usr/share/easyrpmbuilder" && cp -r src/groups/*.grp /usr/share/easyrpmbuilder
echo "cp src/icons/rpm.png /usr/share/easyrpmbuilder" && cp src/icons/rpm.png /usr/share/easyrpmbuilder
echo "cp src/translations/german.qm /usr/share/qt4/translations/easyrpmbuilder_de_DE.qm" && cp src/translations/german.qm /usr/share/qt4/translations/easyrpmbuilder_de_DE.qm
echo "cp src/translations/english.qm /usr/share/qt4/translations/easyrpmbuilder_en_GB.qm" && cp src/translations/english.qm /usr/share/qt4/translations/easyrpmbuilder_en_GB.qm
echo "cp src/translations/spanish.qm /usr/share/qt4/translations/easyrpmbuilder_es_ES.qm" && cp src/translations/spanish.qm /usr/share/qt4/translations/easyrpmbuilder_es_ES.qm
echo "cp src/translations/brazilian.qm /usr/share/qt4/translations/easyrpmbuilder_br_BR.qm" && cp src/translations/brazilian.qm /usr/share/qt4/translations/easyrpmbuilder_br_BR.qm
echo "cp bin/easyrpmbuilder /usr/bin" && cp bin/easyrpmbuilder /usr/bin
cat > /usr/share/applications/easyrpmbuilder.desktop <<EOF
[Desktop Entry]
Encoding=UTF-8
Name=Easy RPM Builder
Name[de]=Easy RPM Builder
Name[es]=Easy RPM Builder
GenericName=RPM Builder
GenericName[es]=Generador de RPMs
GenericName[de]=RPM Builder
Comment=A tool for developers who want to make there application available as RPM packages.
Comment[de]=Ein Werkzeug für Entwickler die Anwendungen als RPM-Pakete erstellen wollen.
Comment[es]=Herramienta para desarrolladores que quieran tener sus aplicaciones disponibles como paquetes RPM.
Exec=/usr/bin/easyrpmbuilder
Icon=/usr/share/easyrpmbuilder/rpm.png
Terminal=false
Type=Application
StartupNotify=true
Categories=Development;Qt;IDE;
EOF
echo "********************************************************************************************"
echo "*                                                                                          *"
echo "* Done!                                                                                    *"
echo "*                                                                                          *"
echo "* If no error messages occurred you can start the program with \"easyrpmbuilder\"          *"
echo "*                                                                                          *"
echo "* Suggestions and bug-reports can be send to joerg.zopes@linux-specialist.com              *"
echo "*                                                                                          *"
echo "********************************************************************************************"
