# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Spelling
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Check for spelling errors in POD files

BUILD_DEPENDS=	p5-Pod-Spell>=0:${PORTSDIR}/textproc/p5-Pod-Spell \
		p5-ExtUtils-MakeMaker>=6.42:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		p5-IPC-Run3>=0:${PORTSDIR}/devel/p5-IPC-Run3
RUN_DEPENDS=	p5-Pod-Spell>=0:${PORTSDIR}/textproc/p5-Pod-Spell \
		p5-IPC-Run3>=0:${PORTSDIR}/devel/p5-IPC-Run3
TEST_DEPENDS=	p5-Test-Tester>=0:${PORTSDIR}/devel/p5-Test-Tester

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
