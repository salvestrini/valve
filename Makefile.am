#
# Makefile.am
#
# (C) 2012 Francesco Salvestrini <salvestrini AT gmail DOT com>
#

ACLOCAL_AMFLAGS = -I m4
DISTCLEANFILES  =
BUILT_SOURCES   =

SUBDIRS         =				\
	src					\
	test

EXTRA_DIST     =				\
	build-aux/git-version-gen		\
	build-aux/gitlog-to-changelog		\
	BUGS					\
	NEWS					\
	.changelog-amend

.PHONY: AUTHORS
AUTHORS:
	$(GIT) log --format="%aN <%aE>" | $(SORT) | $(UNIQ) > AUTHORS || { \
		rm -f AUTHORS ;						   \
		exit 1 ;						   \
	}
EXTRA_DIST     += AUTHORS
DISTCLEANFILES += AUTHORS

.PHONY: ChangeLog
ChangeLog:
	$(srcdir)/build-aux/gitlog-to-changelog				\
		--amend=$(srcdir)/.changelog-amend > ChangeLog || {	\
		rm -f ChangeLog ;					\
		exit 1 ;						\
	}
EXTRA_DIST     += ChangeLog
DISTCLEANFILES += ChangeLog

$(top_srcdir)/.version:
	echo $(VERSION) > $@-t && mv $@-t $@
BUILT_SOURCES  += $(top_srcdir)/.version

dist-hook:
	echo $(VERSION) > $(distdir)/.tarball-version
