#
# Makefile.am
#
# (C) 2012 Francesco Salvestrini <salvestrini AT gmail DOT com>
#

CLEANFILES =
EXTRA_DIST =					\
	test-success				\
	test-failure

edit = $(SED)					\
        -e 's|@SHELL[@]|$(SHELL)|g'		\
        -e 's|@SED[@]|$(SED)|g'			\
        -e 's|@GREP[@]|$(GREP)|g'		\
        -e 's|@DIFF[@]|$(DIFF)|g'		\
        -e 's|@CUT[@]|$(CUT)|g'			\
        -e 's|@HEAD[@]|$(HEAD)|g'		\
        -e 's|@TAIL[@]|$(TAIL)|g'

defs: Makefile
	rm -f $@ $@.tmp
	srcdir=''; \
	  test -f ./$@.in || srcdir=$(srcdir)/; \
	  $(edit) $${srcdir}$@.in >$@.tmp
	chmod +x $@.tmp
	chmod a-w $@.tmp
	mv $@.tmp $@
CLEANFILES += defs
EXTRA_DIST += defs.in

defs: $(srcdir)/defs.in

TESTS_ENVIRONMENT = testdir=@abs_builddir@

scripts =					\
	defs

TESTS	     =					\
	test-success				\
	$(XFAIL_TESTS)
XFAIL_TESTS  =					\
	test-failure

all-local: $(scripts)

clean-local:
	rm -rf test-SUBDIR-*
