TEMPLATE = subdirs

SUBDIRS = \
           libnoise-warp \   # sub-project names
           libnoise-helpers  \
           warpmain \
           diaspora-widgets \
    jstexture \
    libnoise-lua/libnoise-lua \
    libluatest/libluatest

# where to find the sub projects - give the folders
libnoise-warp.subdir    = libnoise-warp
libnoise-helpers.subdir = libnoise-helpers
warpmain.subdir         = warpmain
diaspora-widgets.subdir = diaspora-widgets

# what subproject depends on others
warpmain.depends = libnoise-warp libnoise-helpers
libnoise-helpers.depends = libnoise-warp
