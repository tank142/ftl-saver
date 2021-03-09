pkgname=ftl-saver
pkgver=1
pkgrel=1
pkgdesc="Program for saving progress in the game Faster Than Light"
arch=('x86_64')
url="https://github.com/tank142/ftl-saver"
license=('GPL3')
depends=('qt5-base' 'tar' 'lz4')
makedepends=('git')
source=("${pkgname}::git+https://github.com/tank142/ftl-saver.git")
sha256sums=('SKIP')

build() {
  mkdir -p "${pkgname}/build"
  cd "${pkgname}/build"
  qmake-qt5 PREFIX=/usr \
    QMAKE_CFLAGS_RELEASE="${CFLAGS}" \
    QMAKE_CXXFLAGS_RELEASE="${CXXFLAGS}" \
    QMAKE_LFLAGS_RELEASE="${LDFLAGS}" ..
  make
}

package() {
  make -C "${pkgname}/build" INSTALL_ROOT="$pkgdir/" install
}
