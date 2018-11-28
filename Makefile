SCIPY_VERSION=1.1.0

scipy:
	if [ ! -f "scipy-$(SCIPY_VERSION).tar.gz" ]; then \
		wget https://github.com/scipy/scipy/releases/download/v$(SCIPY_VERSION)/scipy-$(SCIPY_VERSION).tar.gz; \
	fi
	tar -xzf scipy-$(SCIPY_VERSION).tar.gz
	gcc \
		-Iscipy-$(SCIPY_VERSION)/scipy/_lib/src \
		-Iscipy-$(SCIPY_VERSION)/scipy/ndimage/src \
		`python2.7-config --cflags` \
		scipy-$(SCIPY_VERSION)/scipy/ndimage/src/ni_*.c \
		c/*.c \
		`python2.7-config --ldflags` \
		-DNPY_NO_DEPRECATED_API=NPY_1_7_API_VERSION \
		-shared \
		-fPIC \
		-o libgoscipy.so

clean:
	rm scipy-$(SCIPY_VERSION).tar.gz
	rm -r scipy-$(SCIPY_VERSION)
