# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	opencity
PORTVERSION=	0.0.6.4
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Stable/${PORTVERSION:C/^([0-9]+\.[0-9]+\.[0-9]+)\..*$/\1/}/
DISTNAME=	${PORTNAME}-${PORTVERSION}stable

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Free 3D city simulator

GNU_CONFIGURE=	yes
USES=		tar:bzip2 gmake pkgconfig
USE_SDL=	sdl mixer image net
USE_GL=		gl glu
USE_GCC=	any
INSTALL_TARGET=	install-strip

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
