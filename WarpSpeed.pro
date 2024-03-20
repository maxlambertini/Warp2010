TEMPLATE = subdirs

SUBDIRS = \
    libnoise-warp \   # sub-project names
    libnoise-helpers  \
    warpmain

# where to find the sub projects - give the folders
libnoise-warp.subdir    = libnoise-warp
libnoise-helpers.subdir = libnoise-helpers
warpmain.subdir         = warpmain

# what subproject depends on others
warpmain.depends = libnoise-warp libnoise-helpers
libnoise-helpers.depends = libnoise-warp
