# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	xaraya
DISTVERSION=	2.4.0-b1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/Jamaica%20Core/Jamaica%20${DISTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Framework to create fully dynamic Content Management Solutions

LICENSE=	GPLv2

OPTIONS_DEFINE=	PGSQL MYSQL

USES=	tar:bzip2
USE_PHP=	pcre xml simplexml
NO_BUILD=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_PHP+=	mysql
.endif

# May user to override this
XARAYADIR?=	www/xaraya
PLIST_SUB+=	XARAYADIR=${XARAYADIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${XARAYADIR}
	cd ${WRKSRC}/html && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/${XARAYADIR}

.include <bsd.port.mk>
