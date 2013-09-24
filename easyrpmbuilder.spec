Name: easyrpmbuilder
Summary: A rpm package builder helper
Version: 0.5.6
Release: 1%{?dist}
License: GPL v2
Group: Development/Tools/Building 
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)
Source0: %{name}-%{version}.tgz
Packager: Joerg Zopes <joerg.zopes@linux-specialist.com> zy_sunshine <zy.netsec@gmail.com>
Distribution: Magic Linux
Url: http://www.linuxfans.org
Vendor: MGC Group
#Requires: libc.so.6()(64bit) libc.so.6(GLIBC_2.2.5)(64bit) libdl.so.2()(64bit) libfontconfig.so.1()(64bit) libfreetype.so.6()(64bit) libgcc_s.so.1()(64bit) libgcc_s.so.1(GCC_3.0)(64bit) libglib-2.0.so.0()(64bit) libgthread-2.0.so.0()(64bit) libICE.so.6()(64bit) libm.so.6()(64bit) libpng12.so.0()(64bit) libpthread.so.0()(64bit) libQtCore.so.4()(64bit) libQtGui.so.4()(64bit) librt.so.1()(64bit) libSM.so.6()(64bit) libstdc++.so.6()(64bit) libstdc++.so.6(CXXABI_1.3)(64bit) libstdc++.so.6(GLIBCXX_3.4)(64bit) libX11.so.6()(64bit) libXcursor.so.1()(64bit) libXext.so.6()(64bit) libXfixes.so.3()(64bit) libXinerama.so.1()(64bit) libXrandr.so.2()(64bit) libXrender.so.1()(64bit) libz.so.1()(64bit) /usr/bin/rpmbuild

%description
A tool for developers who want to make there application available as RPM packages.
rpm-build has to be installed and you should have a good idea how rpm-build works.
The templates will give you some help how to build your own rpm package for your application

#>%rebuildscript
#>echo Rebuild package for $1 Version $2
#>cd ~/Development/qt4test
#>cp -r $1 $1-$2
#>cd $1-$2
#>make distclean
#>find ./ -name .svn -exec rm -rf {} \; 2>/dev/null
#>cd ..
#>tar -cvzf $1-$2.tgz $1-$2
#>rm -rf $1-$2
#>mv $1-$2.tgz /usr/src/packages/SOURCES
#>echo "* * *  F I N I S H E D  * * *"

%prep
rm -rf %{buildroot}
mkdir %{buildroot}

%setup -q

%build
mkdir -p %{buildroot}%{_bindir}
mkdir -p %{buildroot}%{_datadir}/%{name}
mkdir -p %{buildroot}%{_datadir}/qt4/translations
mkdir -p %{buildroot}%{_datadir}/doc/packages/%{name}/RPM-HOWTO
mkdir -p %{buildroot}%{_datadir}/applications
/usr/lib/qt4/bin/qmake
CFLAGS="$RPM_OPT_FLAGS" CXXFLAGS="$RPM_OPT_FLAGS" \
make
/usr/lib/qt4/bin/lrelease %{name}.pro

%install
cp bin/* %{buildroot}%{_bindir}
cp src/templates/*.tpl %{buildroot}%{_datadir}/%{name}
cp src/groups/*.grp %{buildroot}%{_datadir}/%{name}
cp -r doc/RPM-HOWTO/* %{buildroot}%{_datadir}/doc/packages/%{name}/RPM-HOWTO
cp src/translations/english.qm %{buildroot}%{_datadir}/qt4/translations/%{name}_en_GB.qm
cp src/translations/german.qm %{buildroot}%{_datadir}/qt4/translations/%{name}_de_DE.qm
cp src/translations/spanish.qm %{buildroot}%{_datadir}/qt4/translations/%{name}_es_ES.qm
cp src/translations/brazilian.qm %{buildroot}%{_datadir}/qt4/translations/%{name}_br_BR.qm
cp src/icons/rpm.png %{buildroot}%{_datadir}/%{name}/
cat > $RPM_BUILD_ROOT%{_datadir}/applications/%{name}.desktop <<EOF
[Desktop Entry]
Encoding=UTF-8
Name=%{name}
Comment=A tool for developers who want to make there application available as RPM packages.
Exec=%{_bindir}/%{name}
Icon=%{_datadir}/%{name}/rpm.png
Terminal=false
Type=Application
StartupNotify=true
Categories=Development;Qt;IDE;
EOF

#%kde_post_install


%clean
rm -rf %{buildroot}



%files
%defattr(-,root,root)
%attr(755, root, root) /usr/bin/easyrpmbuilder
%attr(644, root, root) /usr/share/applications/easyrpmbuilder.desktop
%attr(644, root, root) /usr/share/easyrpmbuilder/rpm.png
%attr(766, root, root)/usr/share/easyrpmbuilder/AutoConf_Project_Multimedia.tpl
%attr(766, root, root)/usr/share/easyrpmbuilder/Document_Package_Project.tpl
%attr(766, root, root)/usr/share/easyrpmbuilder/QMake_Project_Development.tpl
%attr(744, root, root) /usr/share/easyrpmbuilder/Fedora.grp
%attr(744, root, root) /usr/share/easyrpmbuilder/MagicLinux.grp
%attr(744, root, root) /usr/share/easyrpmbuilder/Mandriva.grp
%attr(744, root, root) /usr/share/easyrpmbuilder/Mint.grp
%attr(744, root, root) /usr/share/easyrpmbuilder/OpenSuSE.grp
%attr(744, root, root) /usr/share/easyrpmbuilder/Other.grp
%attr(744, root, root) /usr/share/easyrpmbuilder/PCLinuxOS.grp
%attr(744, root, root) /usr/share/easyrpmbuilder/Redhat.grp
%attr(744, root, root) /usr/share/easyrpmbuilder/Ubuntu.grp
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/multi-arch.html
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/oswg.css
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/stylesheet-images/home.gif
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/stylesheet-images/prev.gif
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/stylesheet-images/up.gif
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/build-it.html
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/build.html
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/gen-info.html
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/index.html
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/overview.html
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/rpm-do.html
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/stylesheet-images/caution.gif
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/stylesheet-images/important.gif
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/stylesheet-images/next.gif
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/stylesheet-images/note.gif
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/stylesheet-images/tip.gif
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/stylesheet-images/toc-blank.gif
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/stylesheet-images/toc-minus.gif
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/stylesheet-images/toc-plus.gif
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/stylesheet-images/warning.gif
%attr(644, root, root) /usr/share/doc/packages/easyrpmbuilder/RPM-HOWTO/use.html
%attr(644, root, root) /usr/share/qt4/translations/easyrpmbuilder_de_DE.qm
%attr(644, root, root) /usr/share/qt4/translations/easyrpmbuilder_en_GB.qm
%attr(644, root, root) /usr/share/qt4/translations/easyrpmbuilder_es_ES.qm
%attr(644, root, root) /usr/share/qt4/translations/easyrpmbuilder_br_BR.qm
%docdir /usr/share/doc/packages/easyrpmbuilder

%changelog
* Thu Jan 28 2010 Version 0.5.6. Package rebuild with Easy RPM Builder
- Spanish translation updated
- Error parser improved

* Wed Jan 6 2010 Version 0.5.5. Package rebuild with Easy RPM Builder
- Handling of the toolbars changed (remember position and visibility)
- Config dialog for toolbars (what icon is displayed)
- Fixed a bug in the routine for removing obsolete files from the installation file list
- Translation files updated
- Vendor, packager and homepage can now be set to it default values by clicking a button
- Changed the menu structur

* Mon Jan 4 2010 Version 0.5.4. Package rebuild with Easy RPM Builder
- Recently Used Menu handling improved.
- Print Menu implemented

* Tue Dec 22 2009 Version 0.5.3. Package rebuild with Easy RPM Builder
- implemented support for signing packages (--sign option). If an entry like %_gpg_name is found in the local macro file (~/.rpmmacros) the build process is invoked with --sign option.

* Tue Dec 22 2009 Version 0.5.2. Package rebuild with Easy RPM Builder
- fixed a bug in the save procedure
- changed the look of various dialogs

* Mon Dec 21 2009 Version 0.5.1. Package rebuild with Easy RPM Builder
- handling of the %file sections (%doc %docdir, %config ....) implemented.

* Sun Dec 20 2009 Version 0.5.0. Package rebuild with Easy RPM Builder
- The result window gives more detailed information about the packages build.

* Sun Dec 20 2009 Version 0.4.9. Package rebuild with Easy RPM Builder
- The virtual tag %rebuildscript is saved in the spec file in a way it doesn't
- intervene with the rest of the spec file. 

* Thu Dec 17 2009 Version 0.4.8. Package rebuild with Easy RPM Builder
- script executer implemented though you can update the sources with a single button click

* Wed Dec 16 2009 Version 0.4.7. Package rebuild with Easy RPM Builder
- add folder button reimplemented (got lost ?) for the macro folder dialog

* Tue Dec 15 2009 Version 0.4.6. Package rebuild with Easy RPM Builder
- Error handling / parsing was changed and improved.
- rpmbuild started in en_GB enviroment to force the output to be in english
- A clear list button for requirements, provides, conflicts and obsolete dialog implemented

* Sat Dec 12 2009 Version 0.4.5. Package rebuild with Easy RPM Builder
- fixed some problem with signals and slots in the dialogs.

* Thu Dec 10 2009 Version 0.4.4. Package rebuild with Easy RPM Builder
- Mainly changes in the look and feel and the useability
- Makro viewer / editor changed. Folders with macros can be added or removed from the view.

* Wed Dec 9 2009 Version 0.4.3. Package rebuild with Easy RPM Builder
- Macro Viewer / Editor implemented
- Syntax highlighting improved
- Syntax highlighting for system output added

* Tue Dec 8 2009 Version 0.4.2. Package rebuild with Easy RPM Builder
- Menu structur changed
- Viewer for marcros at /etc/rpm implemented
- second tool bar implemented - toolbars can now be switch on/off

* Tue Dec 08 2009 Version 0.4.1. Package rebuild with Easy RPM Builder
- Brazilian language file added

* Mon Dec 07 2009 Version 0.4.1. Package rebuild with Easy RPM Builder   
- Dialogs for editing of the sources, patches, requires, provides, obsoltes and conflicts section implemented
- Requires will be filled automaticly when the build is done.                                                
- Start logo changed                                                                                         

* Sun Dec 06 2009 Version 0.4.0. Package rebuild with Easy RPM Builder
- added a menu entry in the option menu for managing multiple source files (source0, source1 ...)
- added a menu entry in the option menu for manageing multiple patch files (patch0, patch1 ....) 
- basic syntax highlighting added to the install and build section                               

* Thu Dec 03 2009 Version 0.3.4. Package rebuild with Easy RPM Builder
- Bug in the change-log handling fixed.                              
- Design of the change-log editor changed                            
- process status window implemented                                  

* Wed Dec 02 2009 Version 0.3.4. Package rebuild with Easy RPM Builder
- Handling of the change log entries during save procedure changed   

* Tue Dec 01 2009 Version 0.3.3. Package rebuild with Easy RPM Builder      
- A "recently used" menu added                                             
- Log View Button from the toolbar removed (obsolete)                      
- Automatic load the last used file at program start.                      

* Mon Nov 30 2009 Version 0.3.2. Package rebuild with Easy RPM Builder
- Changes made to the layout of the main application                 
- Parsing the error output and try to give helpful hints for correction
- Some minor flaws removed.                                            

* Sun Nov 29 2009 Version 0.3.1. Package rebuild with Easy RPM Builder
- Fixed the naming of some directories and filenames                 
- Handling for obsolete files in the filelist implemented            

* Mon Nov 23 2009 Version 0.3.0. Package rebuild with Easy RPM Builder
- added some hotkeys for faster actions via keyboard                 

* Sun Nov 22 2009 Version 0.2.9. Package rebuild with Easy RPM Builder
- rpm package fix                                                    

* Sat Nov 21 2009 Version 0.2.9. Package rebuild with Easy RPM Builder
- A problem with the log timestamp fixed                             

* Sat Nov 14 2009 Version 0.2.8. Package rebuild with Easy RPM Builder
- Layout of the mainwindow changed.                                  
- Missing translations added.                                        

* Tue Nov 10 2009 Version 0.2.6. Package rebuild with Easy RPM Builder
- install.sh script fixed                                            
- language selection added to the setting dialog. Now the language file for the application can be preselected
- Spanish translation file added                                                                              

* Fri Nov 06 2009 Version 0.2.5. Package rebuild with Easy RPM Builder
- Template editor fixed                                              
- Templates updated                                                  
- Translation files updated                                          

* Fri Nov 06 2009 Version 0.2.4. Package rebuild with Easy RPM Builder
- A bug in the template editor fixed                                 

* Thu Nov 05 2009 Version 0.2.4. Package rebuild with Easy RPM Builder
- A bug in the template editor fixed                                 

* Wed Nov 04 2009 Version 0.2.3. Package rebuild with Easy RPM Builder
- Some minor bugs within the template handling where fixed
- Order of appearance of the sections within the spec file is changed
- Handling of unsaved changes optimized

* Wed Nov 04 2009 Version 0.2.2. Package rebuild with Easy RPM Builder
- Section management implemented

* Tue Nov 03 2009 Version 0.2.2. Package rebuild with Easy RPM Builder
- Section management implemented

* Tue Nov 03 2009 Version 0.2.1. Package rebuild with Easy RPM Builder
- Bug fix - When open a spec file the group combo box has a wrong value

* Mon Nov 02 2009 Version 0.2.1. Package rebuild with Easy RPM Builder
- Bug fix - When open a spec file the group combo box has a wrong value

* Mon Nov 02 2009 Version 0.2.0. Package rebuild with Easy RPM Builder
- Available groups are now related to the selected distro. Template files reworked.

* Sun Nov 01 2009 Version 0.2.0. Package rebuild with Easy RPM Builder
- Available groups are now related to the selected distro. Template files reworked.

* Sat Oct 31 2009 Version 0.2.0. Package rebuild with Easy RPM Builder
- Available groups are now related to the selected distro. Template files reworked.

* Fri Oct 30 2009 Version 0.1.4. Package rebuild with Easy RPM Builder
- Spec File Templates and handling changed

* Fri Oct 30 2009 Version 0.1.4. Package rebuild with Easy RPM Builder
- project renamed from easyrpm to easyrpmbuilder

* Tue Oct 27 2009 Version 0.1.3. Package rebuild with easyrpm
- Change Log Viewer Implemented

* Tue Oct 27 2009 Version 0.1.2. Package rebuild with easyrpm
- Toolbar added
