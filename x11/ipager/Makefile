# Created by: Vlad V. Teterya <vlad@vlad.uz.ua>
# $FreeBSD$

PORTNAME=	ipager
PORTVERSION=	1.1.0
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	http://useperl.ru/ipager/src/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	X11 pager program

LICENSE=	MIT

USES=		scons
USE_EFL=	imlib2

SUB_FILES=	pkg-message

DOCS=		ChangeLog README ToDo
THEMES=		atlantis.conf \
		dark_red.conf \
		green.conf \
		industrial.conf \
		light_gray.conf \
		light_orange.conf

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '35,36d;89d;92,94d' \
		-e "s/\([^-]pthread'\)/\1, 'X11'/" \
		${WRKSRC}/SConstruct

pre-build:
	# scons is too stupid to create DESTDIR by itself
	@${MKDIR} ${WRKDIR}/stage

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}/themes
.for t in ${THEMES}
	${INSTALL_DATA} ${WRKSRC}/themes/${t} ${STAGEDIR}${DATADIR}/themes
.endfor
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ipager

.include <bsd.port.mk>
