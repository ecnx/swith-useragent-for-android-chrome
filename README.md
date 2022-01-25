# swith-useragent-for-android-chrome
Custom useragent on Android Chrome? Yes it's possible!

apply patch p1.patch with Chromium source code branch 4664

set config like this in /sdcard/chromium-vprops:

'''
    sys.ro.build.version.release=6.9.9
    sys.ro.product.manufacturer=samsung
    sys.ro.product.model=SM-J710X
    sys.ro.build.version.codename=REL
    sys.ro.build.id=MMB29K
    sys.ro.hardware.egl=
    web.navigator.deviceMemory=4
    web.navigator.hardwareConcurrency=3
    app.chrome.product=ChromX/123
    app.chrome.greased_product=Chroome
    app.chrome.greased_version=123
    app.chrome.full_version=94.1.2.3
    net.connecion.type=wifi
    sys.gpu.renderer=Mali-T213
    sys.gpu.vendor=AMR
  '''
