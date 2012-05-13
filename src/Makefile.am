#
# Makefile.am
#
# (C) 2012 Francesco Salvestrini <salvestrini AT gmail DOT com>
#

SUBDIRS = ptree

bin_PROGRAMS = valve

valve_SOURCES =					\
	options.cc   options.hh			\
	utils.cc     utils.hh			\
	ptree.cc     ptree.hh			\
	cfgraph.cc   cfgraph.hh			\
	ast.cc       ast.hh			\
	bytecode.cc  bytecode.hh		\
	defs.hh					\
	valve.cc

valve_LDADD = ptree/libptree.a
