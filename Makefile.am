ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS = -I include 

lib_LTLIBRARIES = src/libvyatta-util.la
src_libvyatta_util_la_LDFLAGS = -version-info 1:0:0
src_libvyatta_util_la_SOURCES = src/type_check.c
src_libvyatta_util_la_SOURCES += src/misc.c
LDADD = src/libvyatta-util.la

sbin_PROGRAMS = src/ipset-check-member
sbin_PROGRAMS += src/vyatta-validate-type

src_ipset_check_member_SOURCES = src/ipset-check-member.c
src_vyatta_validate_type_SOURCES = src/vyatta-validate-type.c

vincludedir = $(includedir)/vyatta-util
vinclude_HEADERS = include/misc.h
vinclude_HEADERS += include/type_check.h
