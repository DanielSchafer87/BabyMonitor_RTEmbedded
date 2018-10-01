# invoke SourceDir generated makefile for release.pem4
release.pem4: .libraries,release.pem4
.libraries,release.pem4: package/cfg/release_pem4.xdl
	$(MAKE) -f C:\Users\DANIEL~1\workspace_v8\BabyMonitor_RTEmbedded_ZoharDaniel/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\DANIEL~1\workspace_v8\BabyMonitor_RTEmbedded_ZoharDaniel/src/makefile.libs clean

