# Created by: Evgueni V. Gavrilov <aquatique@rusunix.org>
# $FreeBSD$

PORTNAME=	bopm
PORTVERSION=	3.1.3
PORTREVISION=	2
CATEGORIES=	irc
MASTER_SITES=	http://static.blitzed.org/www.blitzed.org/bopm/files/ \
		ftp://rusunix.org/pub/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open proxy and DNSBL monitor designed for use with ircds

LOGDIR=		/var/log/${PORTNAME}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${LOGDIR}
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes
USE_RC_SUBR=	bopm

PLIST_SUB=	LOGDIR=${LOGDIR}

USERS=	bopm
GROUPS=	bopm

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's,/some/path/bopm.pid,/var/run/bopm.pid,g' \
		-e 's,/some/path/scan.log,${LOGDIR}/scan.log,g' \
		${WRKSRC}/bopm.conf.sample

.include <bsd.port.mk>
