.PHONY: FORCE
all: FORCE
	$(MAKE) -C .. bluecoin_qt test_bluecoin_qt
clean: FORCE
	$(MAKE) -C .. bluecoin_qt_clean test_bluecoin_qt_clean
check: FORCE
	$(MAKE) -C .. test_bluecoin_qt_check
bluecoin-qt bluecoin-qt.exe: FORCE
	 $(MAKE) -C .. bluecoin_qt
apk: FORCE
	$(MAKE) -C .. bluecoin_qt_apk
