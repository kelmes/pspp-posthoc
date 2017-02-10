## Process this file with automake to produce Makefile.in  -*- makefile -*-

language_expressions_sources = \
	src/language/expressions/evaluate.c \
	src/language/expressions/helpers.c \
	src/language/expressions/helpers.h \
	src/language/expressions/optimize.c \
	src/language/expressions/parse.c \
	src/language/expressions/private.h \
	src/language/expressions/public.h

expressions_built_sources = \
	src/language/expressions/evaluate.h \
	src/language/expressions/evaluate.inc \
	src/language/expressions/operations.h \
	src/language/expressions/optimize.inc \
	src/language/expressions/parse.inc

BUILT_SOURCES += $(expressions_built_sources)
CLEANFILES += $(expressions_built_sources)

helpers = src/language/expressions/generate.pl \
	src/language/expressions/operations.def
EXTRA_DIST += $(helpers)

$(expressions_built_sources): $(helpers)
	$(AV_V_GEN)$(MKDIR_P) `dirname $@` && \
	$(PERL) $< -o $@ -i $(top_srcdir)/src/language/expressions/operations.def

AM_CPPFLAGS += -I$(top_builddir)/src/language/expressions \
	-I$(top_srcdir)/src/language/expressions

EXTRA_DIST += src/language/expressions/TODO
