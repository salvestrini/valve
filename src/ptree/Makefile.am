#
# Makefile.am
#
# (C) 2012 Francesco Salvestrini <salvestrini AT gmail DOT com>
#

noinst_LIBRARIES = libptree.a

libptree_a_SOURCES =				\
	parser.cc				\
	scanner.cc				\
	driver.cc

EXTRA_DIST =					\
	scanner.ll				\
	parser.yy				\
	driver.hh

MOSTLYCLEANFILES =

MOSTLYCLEANFILES +=				\
	parser.stamp				\
	parser.tmp				\
	parser.cc				\
	parser.hh				\
	stack.hh				\
	position.hh				\
	location.hh

MOSTLYCLEANFILES +=				\
	scanner.stamp				\
	scanner.tmp				\
	scanner.cc				\
	scanner.hh

FLEX_OPTIONS = --batch
 
scanner.stamp: $(srcdir)/scanner.ll Makefile
	rm -f scanner.tmp
	touch scanner.tmp
	$(FLEX) $(FLEX_OPTIONS)			\
		--outfile=scanner.cc		\
		--header-file=scanner.hh	\
		$(srcdir)/scanner.ll || {	\
		rm -f scanner.cc ;		\
		rm -f scanner.hh ;		\
		exit 1 ;			\
	}
	mv -f scanner.tmp $@

scanner.cc scanner.hh: scanner.stamp
	if test ! -f $@; then				\
		rm -f scanner.stamp ;			\
		$(MAKE) $(AM_MAKEFLAGS) scanner.stamp ;	\
	fi

BISON_OPTIONS =

parser.stamp: $(srcdir)/parser.yy Makefile
	rm -f parser.tmp
	touch parser.tmp
	$(BISON) $(BISON_OPTIONS)		\
		--defines=parser.hh		\
		--language=C++			\
		-o parser.cc			\
		$(srcdir)/parser.yy || {	\
		rm -f parser.cc ;		\
		rm -f parser.hh ;		\
		exit 1 ;			\
	}
	mv -f parser.tmp $@

parser.cc parser.hh: parser.stamp
	if test ! -f $@ ; then				\
		rm -f parser.stamp ;			\
		$(MAKE) $(AM_MAKEFLAGS) parser.stamp ;	\
	fi
