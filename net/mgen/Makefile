# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	mgen
PORTVERSION=	4.2b6
CATEGORIES=	net
MASTER_SITES=	http://downloads.pf.itd.nrl.navy.mil/mgen/archive/mgen4/ \
	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi
DISTNAME=	src-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP network performance tests and measurements

# Dumps core on 64-bit architectures. This was reported to the upstream
# author, who promised to fix it in one of the next releases.
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake tar:tgz
MAKEFILE=	Makefile.freebsd

PLIST_FILES=	bin/mgen
PORTDOCS=	README.TXT VERSION.TXT mgen.html example.mgn

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/unix/Makefile.common \
		${WRKSRC}/protolib/unix/Makefile.common

	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|g; \
		s|g++|${CXX}|; s|gcc|${CC}|; /CFLAGS =/s|$$|${CFLAGS}|' \
		${WRKSRC}/unix/Makefile.freebsd \
		${WRKSRC}/protolib/unix/Makefile.freebsd

do-build:
	${DO_MAKE_BUILD} -C ${WRKSRC}/unix ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix/mgen ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
