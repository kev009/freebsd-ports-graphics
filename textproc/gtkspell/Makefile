# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/textproc/gtkspell/Makefile,v 1.2 2006/09/10 00:51:13 mezz Exp $

PORTNAME=	gtkspell
PORTVERSION=	2.0.16
PORTREVISION?=	5
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	marcus

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK+ 2 spell checking component

.if !defined(REFERENCE_PORT)

LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant

USES=		gettext gmake libtool:keepla pathfix pkgconfig
USE_GNOME=	gnomeprefix gtk20 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|docs||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

.endif
