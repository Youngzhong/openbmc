HOMEPAGE = "https://github.com/open-power"
LICENSE = "Apache-2.0"

SRC_URI += "git://github.com/open-power/skiboot.git;nobranch=1"
SRC_URI += "file://0001-external-Use-more-standard-PREFIX-vs-prefix.patch"
SRC_URI += "file://0002-external-Utilize-DESTDIR-in-shared-makefile.patch"
SRC_URI += "file://0003-gard-Fix-Makefile-race-condition.patch"

FILESEXTRAPATHS_append := "${THISDIR}/skiboot:"

LIC_FILES_CHKSUM = "file://${S}/LICENCE;md5=3b83ef96387f14655fc854ddc3c6bd57"

SRCREV = "skiboot-5.3.5"
PV = "5.3.5"

S = "${WORKDIR}/git"

EXTRA_OEMAKE = "CROSS_COMPILE=${TARGET_PREFIX} SKIBOOT_VERSION=${PV} V=1"

SKIBOOT_SUBDIR ?= "external/${PN}"

do_compile() {
    oe_runmake -C ${SKIBOOT_SUBDIR} all
}

do_install() {
    oe_runmake -C ${SKIBOOT_SUBDIR} install DESTDIR=${D} PREFIX=/usr
}
