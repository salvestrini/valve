#
# Makefile.am
#
# (C) 2012 Francesco Salvestrini <salvestrini AT gmail DOT com>
#

CLEANFILES =
EXTRA_DIST =

edit = $(SED)							\
	-e 's|@abs_top_builddir[@]|$(abs_top_builddir)|g'	\
        -e 's|@SHELL[@]|$(SHELL)|g'				\
        -e 's|@SED[@]|$(SED)|g'					\
        -e 's|@GREP[@]|$(GREP)|g'				\
        -e 's|@DIFF[@]|$(DIFF)|g'				\
        -e 's|@CUT[@]|$(CUT)|g'					\
        -e 's|@HEAD[@]|$(HEAD)|g'				\
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
	test-parsing-01				\
	test-parsing-02				\
	$(XFAIL_TESTS)
XFAIL_TESTS  =					\
	test-failure

EXTRA_DIST += $(TESTS)

all-local: $(scripts)

clean-local:
	rm -rf test-SUBDIR-*
