#
# Makefile.am
#
# (C) 2012 Francesco Salvestrini <salvestrini AT gmail DOT com>
#

noinst_LIBRARIES = libptree.a

libptree_a_SOURCES =				\
	parser.cc				\
	lexer.cc

EXTRA_DIST =					\
	lexer.ll				\
	parser.yy

MOSTLYCLEANFILES =				\
	parser.hh				\
	lexer.cc				\
	parser.stamp				\
	stack.hh				\
	parser.cc				\
	position.hh				\
	lexer.hh				\
	lexer.stamp				\
	location.hh

FLEX_OPTIONS  = -c++ --batch
 
lexer.stamp: $(srcdir)/lexer.ll Makefile
	rm -f lexer.tmp
	touch lexer.tmp
	$(FLEX) $(FLEX_OPTIONS)			\
		--outfile=lexer.cc		\
		--header-file=lexer.hh		\
		$(srcdir)/lexer.ll || {		\
		rm -f lexer.cc ;		\
		rm -f lexer.hh ;		\
		exit 1 ;			\
	}
	mv -f lexer.tmp $@

lexer.cc lexer.hh: lexer.stamp
	if test -f $@; then :; else		\
	  rm -f lexer.stamp;			\
	  $(MAKE) $(AM_MAKEFLAGS) lexer.stamp;	\
	fi

BISON_OPTIONS = -L C++ -d

parser.stamp: $(srcdir)/parser.yy Makefile
	rm -f parser.tmp
	touch parser.tmp
	$(BISON) $(BISON_OPTIONS)		\
		-o parser.cc			\
		$(srcdir)/parser.yy || {	\
		rm -f parser.cc ;		\
		rm -f parser.hh ;		\
		exit 1 ;			\
	}
	mv -f parser.tmp $@

parser.cc parser.hh: parser.stamp
	if test -f $@; then :; else		\
	  rm -f parser.stamp;			\
	  $(MAKE) $(AM_MAKEFLAGS) parser.stamp;	\
	fi
