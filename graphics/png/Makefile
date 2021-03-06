# Created by: ache
# $FreeBSD$

PORTNAME=	png
PORTVERSION=	1.5.19
CATEGORIES=	graphics
MASTER_SITES=	SF/lib${PORTNAME}/lib${PORTNAME}15/${PORTVERSION}
DISTNAME=	lib${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Library for manipulating PNG images

PORTSCOUT=	limit:^1\.5\.

USES=		tar:xz cmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DPNG_MAN_DIR:STRING=man
SOSUFFIX=	.${PORTVERSION:E}

OPTIONS_DEFINE=APNG PNGTEST
OPTIONS_DEFAULT=APNG PNGTEST
APNG_DESC=Enable Animated PNG support
PNGTEST_DESC=Enable Regression Test (recommended)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPNG} || make(makesum) || defined(FETCH_ALL)
MASTER_SITES+=	SF/apng/libpng/libpng15/:apng
DISTFILES+=	${DISTNAME}-apng.patch.gz:apng
EXTRACT_ONLY+=	${DISTNAME}${EXTRACT_SUFX}
.endif
.if ${PORT_OPTIONS:MAPNG}
EXTRA_PATCHES+=	${WRKSRC}/${DISTNAME}-apng.unix
.endif

post-extract:
.if ${PORT_OPTIONS:MAPNG}
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}-apng.patch.gz ${WRKSRC}/
	${GZIP_CMD} -d ${WRKSRC}/${DISTNAME}-apng.patch.gz
	${TR} -d '\r' < ${WRKSRC}/${DISTNAME}-apng.patch > ${WRKSRC}/${DISTNAME}-apng.unix
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's|RELEASE}.0|RELEASE}|' \
		-e 's|LIBDIR}/pkgconfig|LIBDIR}data/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.if ${PORT_OPTIONS:MPNGTEST}
post-build:
	(cd ${BUILD_WRKSRC}; if ! ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} test; then \
        if [ x != x${BUILD_FAIL_MESSAGE} ] ; then \
            ${ECHO_MSG} "===> Compilation failed unexpectedly."; \
            (${ECHO_CMD} ${BUILD_FAIL_MESSAGE}) | ${FMT} 75 79 ; \
            fi; \
        ${FALSE}; \
        fi)
.endif

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/libpng
	${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/pngdebug.h ${WRKSRC}/pnginfo.h \
		${WRKSRC}/pngpriv.h ${WRKSRC}/pngstruct.h \
		${STAGEDIR}${PREFIX}/include/libpng15/
	-${RMDIR} ${STAGEDIR}${PREFIX}/include/libpng
	${RM} ${STAGEDIR}${PREFIX}/libdata/pkgconfig/libpng.pc
	${LN} -sf libpng15.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/libpng.pc
	${RM} ${STAGEDIR}${PREFIX}/lib/libpng15.so.15
	${MV} ${STAGEDIR}${PREFIX}/lib/libpng15.so.15${SOSUFFIX} ${STAGEDIR}${PREFIX}/lib/libpng15.so.15

.include <bsd.port.mk>
