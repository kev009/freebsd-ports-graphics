# Created by: Juergen Lock <nox@jelal.kn-bremen.de>
# $FreeBSD$

PORTNAME=	qemu
PORTVERSION=	2.0.2
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	http://wiki.qemu.org/download/:release \
		LOCAL/nox:snapshot
PKGNAMESUFFIX?=	-devel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:release
DIST_SUBDIR=	qemu/${PORTVERSION}

MAINTAINER=	nox@FreeBSD.org
COMMENT?=	QEMU CPU Emulator - development version

HAS_CONFIGURE=	yes
USES=		gmake pkgconfig bison perl5 python:2,build tar:bzip2
USE_PERL5=	build
USE_XORG=	pixman
USE_GNOME+=	glib20
PATCH_STRIP=	-p1
MAKE_ENV+=	BSD_MAKE="${MAKE}"
ONLY_FOR_ARCHS=	amd64 i386 powerpc powerpc64 # XXX someone wants to debug sparc64 hosts?

OPTIONS_DEFINE=	SAMBA X11 GTK2 OPENGL GNUTLS SASL JPEG PNG CURL \
		CDROM_DMA PCAP USBREDIR GNS3 X86_TARGETS BSD_USER \
		STATIC_LINK DOCS
SAMBA_DESC=		samba dependency (for -smb)
GNUTLS_DESC=		gnutls dependency (vnc encryption)
SASL_DESC=		cyrus-sasl dependency (vnc encryption)
JPEG_DESC=		jpeg dependency (vnc lossy compression)
PNG_DESC=		png dependency (vnc compression)
CDROM_DMA_DESC=		IDE CDROM DMA
PCAP_DESC=		pcap dependency (networking with bpf)
USBREDIR_DESC=		usb device network redirection (experimental!)
GNS3_DESC=		gns3 patches (promiscuous multicast)
X86_TARGETS_DESC=	Don't build non-x86 system targets
BSD_USER_DESC=		Also build bsd-user targets (for testing)
STATIC_LINK_DESC=	Statically link the executables
OPTIONS_DEFAULT=X11 GTK2 OPENGL GNUTLS SASL JPEG PNG CDROM_DMA CURL PCAP

.if !defined(QEMU_USER_STATIC)
CONFLICTS_INSTALL=	qemu-[0-9]*
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBSD_USER}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-790d0ef625d22ff3f1a895d266a48e2bacd63776
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-3d175d6ed5b809976662135369c639f53780ca5c
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-a3129eea10f188bfd39ce83b18b25dcefbc5bffc
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-fd7ec8e06cd1876ef478975f052ff64134d19c6c
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-9ac2c49c734a49025fe1647ce84728d3988ea5d2
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-38f8d5aaebdb4b1624bae86b374b5265c9f01b54
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-c13_tls2
#
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bsd-user-freebsd-os-proc.c
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-05ee8495804599b52a88eb36b13ea9c06b3207cd
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bsd-user-mips-target_arch_vmparam.h
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-inherit-interp_prefix
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-d62553b108aa27c0c020dbb771d29f8673807a3b
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-6201cb17ad905dffee1b2eb76f58fb032e99b2a1
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bsd-user-syscall.c
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-sysctl-hw-availpages
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-sysctl-0oldlen
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bsd-user-mmap.c
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-sysctl-hw-pagesizes
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bsd-user-x86_64-target_arch_vmparam.h
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-target_siginfo
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bsd-user-arm-signal
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-getvfsbyname
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-kernproc
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bsd-user-freebsd-target_os_stack.h
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bsd-user-arm-target_arch_thread.h
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bsd-user-sparc64-target_arch_cpu.h
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bsd-user-trapsig
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-21927cffcc7bcacbb953155f778200846df9f60e
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bsd-user-freebsd-os-sys.c
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-sysctl-hw-physmem
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-max-arg-pages
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-ad92220df37d1ab3120316fcc436071c78817561
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-2478a4e4a33d0523cc436eabb4a27b258b4358b8
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-ac9f83019a2059d4bfe5cedfae35ba4151d5ac88
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-d9388715135ed1f36e12e6cdbcc1be09d1657916
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-c9c55ac786f09ce575b5f67b35241ce9452896c9
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-5f81caf45c0d0eb2b4b852f8580a1938fb3d12c6
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-f32d585446698e1faa319c95df6b4d00c16f866c
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-a6402a4b7077af85733a1c98d63ab09f02d980ec
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-30c8ccb41e2c9e1ddda7e3f8a8ac1eb5dab8b408
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-22b23eb877a8a5ec251b4ae0e71e3c7ce5397721
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-1ebbb5b56e890741f1461662fae9728da0c76e27
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-93cf90cb04fee057a710be43614b033e6b2e86d1
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-ad225b8412847303d48d8e7852589456325e8f9b
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-3ed485b9b4ef8d8ba916760aec0cdf9dbce8ca27
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-72f0a64c7dd7be796dc2d8f2b0dab340309800e2
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-9ed0e07e2e07791858339874eb4d20daca858c8a
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-a8dc4de7f73bc6f8363c0fc81c4c6e53733c444b
.endif

CONFIGURE_ARGS+=	--extra-ldflags=-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--disable-smartcard-nss --disable-libssh2
PORTDOCS=	docs qemu-doc.html qemu-tech.html qmp-commands.txt

.if defined(QEMU_USER_STATIC)
.if ${ARCH} != "amd64"
CONFIGURE_ARGS+=	--target-list=i386-bsd-user,sparc-bsd-user,arm-bsd-user,mips-bsd-user,mipsel-bsd-user
.else
CONFIGURE_ARGS+=	--target-list=i386-bsd-user,x86_64-bsd-user,sparc-bsd-user,sparc64-bsd-user,arm-bsd-user,mips-bsd-user,mipsel-bsd-user,mips64-bsd-user,mips64el-bsd-user
.endif
.else
.if ${PORT_OPTIONS:MX86_TARGETS}
.if ${PORT_OPTIONS:MBSD_USER}
.if ${ARCH} != "amd64"
CONFIGURE_ARGS+=	--target-list=i386-softmmu,x86_64-softmmu,i386-bsd-user,sparc-bsd-user,arm-bsd-user,mips-bsd-user,mipsel-bsd-user
.else
CONFIGURE_ARGS+=	--target-list=i386-softmmu,x86_64-softmmu,i386-bsd-user,x86_64-bsd-user,sparc-bsd-user,sparc64-bsd-user,arm-bsd-user,mips-bsd-user,mipsel-bsd-user,mips64-bsd-user,mips64el-bsd-user
.endif
.else
CONFIGURE_ARGS+=	--target-list=i386-softmmu,x86_64-softmmu
.endif
.else
.if empty(PORT_OPTIONS:MBSD_USER)
CONFIGURE_ARGS+=	--disable-bsd-user
.else
.if ${ARCH} != "amd64"
CONFIGURE_ARGS+=	--target-list=i386-softmmu,x86_64-softmmu,aarch64-softmmu,alpha-softmmu,arm-softmmu,cris-softmmu,lm32-softmmu,m68k-softmmu,microblaze-softmmu,microblazeel-softmmu,mips-softmmu,mipsel-softmmu,mips64-softmmu,mips64el-softmmu,or32-softmmu,ppc-softmmu,ppcemb-softmmu,ppc64-softmmu,sh4-softmmu,sh4eb-softmmu,sparc-softmmu,sparc64-softmmu,s390x-softmmu,xtensa-softmmu,xtensaeb-softmmu,unicore32-softmmu,moxie-softmmu,i386-bsd-user,sparc-bsd-user,arm-bsd-user,mips-bsd-user,mipsel-bsd-user
.endif
.endif
.endif
.endif

.if empty(PORT_OPTIONS:MBSD_USER)
PLIST_SUB+=	BSD_USER="@comment "
.else
PLIST_SUB+=	BSD_USER=""
.if ${ARCH} == "sparc64"
IGNORE=		bsd-user targets not tested on sparc64
.endif
.endif
.if empty(PORT_OPTIONS:MBSD_USER) || ${ARCH} != "amd64"
PLIST_SUB+=	BSD_USER64="@comment "
.else
PLIST_SUB+=	BSD_USER64=""
.endif

.if ${PORT_OPTIONS:MX86_TARGETS}
PLIST_SUB+=	NONX86="@comment "
.else
PLIST_SUB+=	NONX86=""
.endif

.if defined(QEMU_USER_STATIC)
PLIST_SUB+=	SOFTMMU="@comment "
PLIST_SUB+=	STATIC="-static"
.else
PLIST_SUB+=	SOFTMMU=""
PLIST_SUB+=	STATIC=""
.endif

.if ${PORT_OPTIONS:MGNS3}
EXTRA_PATCHES+=	${FILESDIR}/hw_e1000_c.patch
.endif

WITHOUT_CPU_CFLAGS=yes	#to avoid problems with register allocation
CFLAGS:=	${CFLAGS:C/-fno-tree-vrp//}
CONFIGURE_ARGS+=	--prefix=${PREFIX} --cc=${CC} --enable-docs \
	--disable-linux-user --disable-linux-aio \
	--disable-kvm --disable-xen \
	--smbd=${LOCALBASE}/sbin/smbd \
	--enable-debug \
	--enable-debug-info \
	--extra-cflags=-I${WRKSRC}\ -I${LOCALBASE}/include\ -DPREFIX=\\\"${PREFIX}\\\"

.if empty(PORT_OPTIONS:MX11)
CONFIGURE_ARGS+=	--disable-sdl
.else
CONFIGURE_ARGS+=	--enable-sdl
USE_SDL=	sdl
.endif

.if empty(PORT_OPTIONS:MGTK2)
CONFIGURE_ARGS+=	--disable-gtk --disable-vte
PLIST_SUB+=	GTK2="@comment "
.else
USE_GNOME+=	gtk20 vte
USES+=		gettext
PLIST_SUB+=	GTK2=""
.endif

.if empty(PORT_OPTIONS:MGNUTLS)
CONFIGURE_ARGS+=	--disable-vnc-tls
.else
LIB_DEPENDS+=	libgnutls.so:${PORTSDIR}/security/gnutls
.endif

.if empty(PORT_OPTIONS:MSASL)
CONFIGURE_ARGS+=	--disable-vnc-sasl
.else
LIB_DEPENDS+=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
.endif

.if empty(PORT_OPTIONS:MJPEG)
CONFIGURE_ARGS+=	--disable-vnc-jpeg
.else
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg
.endif

.if empty(PORT_OPTIONS:MPNG)
CONFIGURE_ARGS+=	--disable-vnc-png
.else
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
.endif

.if empty(PORT_OPTIONS:MCURL)
CONFIGURE_ARGS+=	--disable-curl
.else
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
.endif

.if empty(PORT_OPTIONS:MOPENGL)
CONFIGURE_ARGS+=	--disable-glx
.else
USE_GL=		yes
.endif

.if empty(PORT_OPTIONS:MUSBREDIR)
CONFIGURE_ARGS+=	--disable-usb-redir
.else
BUILD_DEPENDS+=	usbredir>=0.6:${PORTSDIR}/net/usbredir
RUN_DEPENDS+=	usbredir>=0.6:${PORTSDIR}/net/usbredir
.endif

.if ${PORT_OPTIONS:MPCAP}
CONFIGURE_ARGS+=	--enable-pcap
.endif

.if ${PORT_OPTIONS:MSTATIC_LINK}
.if ${PORT_OPTIONS:MGTK2} || ${PORT_OPTIONS:MX11}
IGNORE=		X11 ui cannot be built static
.endif
CONFIGURE_ARGS+=	--static
.endif

.if ${PORT_OPTIONS:MSAMBA}
RUN_DEPENDS+=	${LOCALBASE}/sbin/smbd:${PORTSDIR}/net/samba36
.endif

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
USES+=		makeinfo
.else
MAKE_ARGS+=	NOPORTDOCS=1
.endif

.if !defined(STRIP) || ${STRIP} == ""
CONFIGURE_ARGS+=--disable-strip
.endif

.if ${ARCH} == "amd64"
MAKE_ARGS+=	ARCH=x86_64
.endif

.if ${ARCH} == "powerpc"
MAKE_ARGS+=	ARCH=ppc
.endif

.if ${ARCH} == "powerpc64"
MAKE_ARGS+=	ARCH=ppc64
.endif

.if ${ARCH} == "sparc64"
CONFIGURE_ARGS+= --sparc_cpu=v9
.endif

.if ${OSVERSION} < 900033
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
CONFIGURE_ENV+=	LD=${LOCALBASE}/bin/ld
CONFIGURE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
MAKE_ENV+=	COMPILER_PATH=${LOCALBASE}/bin
.endif

CONFIGURE_ARGS+= --python=${PYTHON_CMD}

# -lprocstat actually only _needs_ -lelf after r249666 or r250870 (MFC)
# but it shouldn't matter much
post-patch:
.if ${OSVERSION} < 900000
	@${REINPLACE_CMD} -e '/LIBS/s|-lprocstat||' ${WRKSRC}/configure
.else
	@${REINPLACE_CMD} -e '/LIBS/s|-lprocstat|-lprocstat -lelf|' \
		${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e '/libs_qga=/s|glib_libs|glib_libs -lintl|' ${WRKSRC}/configure
.if ${PORT_OPTIONS:MPCAP}
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/pcap-patch
.endif
.if empty(PORT_OPTIONS:MCDROM_DMA)
	@cd ${WRKSRC} && ${PATCH} --quiet < ${FILESDIR}/cdrom-dma-patch
.endif
	@${REINPLACE_CMD} -E \
		-e "/^by Tibor .TS. S/s|Sch.*z.$$|Schuetz.|" \
		${WRKSRC}/qemu-doc.texi
	@${REINPLACE_CMD} -E \
		-e "s|^(CFLAGS=).*|\1${CFLAGS} -fno-strict-aliasing|" \
		-e "s|^(LDFLAGS=).*|\1${LDFLAGS}|" \
		${WRKSRC}/Makefile.target
	@${REINPLACE_CMD} -E \
		-e "s|^(CFLAGS=).*|\1${CFLAGS} -fno-strict-aliasing -I.|" \
		-e "s|^(LDFLAGS=).*|\1${LDFLAGS}|" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E \
		-e "1s|^(#! )/usr/bin/perl|\1${PERL}|" \
		${WRKSRC}/scripts/texi2pod.pl

.if ${OSVERSION} >= 800091
# XXX need to disable usb host code on head while it's not ported to the
# new usb stack yet
post-configure:
	@${REINPLACE_CMD} -E \
		-e "s|^(HOST_USB=)bsd|\1stub|" \
		${WRKSRC}/config-host.mak
.endif

.if !target(post-install)
post-install:
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DOCSDIR}/)
.endif
	@${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifup.sample ${STAGEDIR}${PREFIX}/etc
	@${INSTALL_SCRIPT} ${FILESDIR}/qemu-ifdown.sample ${STAGEDIR}${PREFIX}/etc
	@(cd ${STAGEDIR}${PREFIX}/etc/qemu && \
		${MV} -i target-x86_64.conf target-x86_64.conf.sample)
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qemu-*
.endif

.include <bsd.port.mk>
