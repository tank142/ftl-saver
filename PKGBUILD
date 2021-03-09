pkgname=ftl-saver
pkgver=1
pkgrel=1
pkgdesc="Program for saving progress in the game Faster Than Light"
arch=('x86_64')
url="https://github.com/tank142/ftl-saver"
license=('GPL3')
depends=('qt5-base' 'tar' 'lz4')
makedepends=('git')
optdepends=
source=('wine-gui::git+https://github.com/tank142/wine-gui.git')
sha256sums=('SKIP')

pkgver() {
  cd "${pkgname%-*}"
  git describe --long --tags | sed -r 's/([^-]*-g)/r\1/;s/-/./g'
}

build() {
  cd "${pkgname%-*}"
  qmake-qt5 PREFIX=/usr \
    QMAKE_CFLAGS_RELEASE="${CFLAGS}" \
    QMAKE_CXXFLAGS_RELEASE="${CXXFLAGS}" \
    QMAKE_LFLAGS_RELEASE="${LDFLAGS}"
  make
}

package() {
  make -C "${pkgname%-*}" INSTALL_ROOT="$pkgdir/" install
}
