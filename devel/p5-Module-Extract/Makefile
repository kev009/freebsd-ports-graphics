# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Module-Extract
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Base class for working with Perl distributions

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Archive-Extract>=0:${PORTSDIR}/archivers/p5-Archive-Extract
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
