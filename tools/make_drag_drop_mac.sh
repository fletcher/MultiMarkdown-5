#!/bin/sh

#	Run this in terminal (with the Platypus command line tool installed)
#	to create drag and drop binaries.  NOTE: These rarely need to be 
#	updated, and rely on whatever version of MultiMarkdown you have
#	installed.

# Modified for Platypus version 5

/usr/local/bin/platypus  --droppable --quit-after-execution \
--name 'MMD to HTML'  --output-type 'Text Window'  --interpreter '/bin/sh' \
--bundle-identifier net.fletcherpenney.MMD2HTML --suffixes '*' \
'../scripts/mmd' -y MMD2HTML.app

/usr/local/bin/platypus  --droppable --quit-after-execution \
--name 'MMD to LaTeX'  --output-type 'Text Window'  --interpreter '/bin/sh' \
--bundle-identifier net.fletcherpenney.MMD2LaTeX --suffixes '*' \
'../scripts/mmd2tex' -y MMD2LaTeX.app

/usr/local/bin/platypus  --droppable --quit-after-execution \
--name 'MMD to OPML'  --output-type 'Text Window'  --interpreter '/bin/sh' \
--bundle-identifier net.fletcherpenney.MMD2OPML --suffixes '*' \
'../scripts/mmd2opml' -y MMD2OPML.app

/usr/local/bin/platypus  --droppable --quit-after-execution \
--name 'MMD to ODF'  --output-type 'Text Window'  --interpreter '/bin/sh' \
--bundle-identifier net.fletcherpenney.MMD2ODF --suffixes '*' \
'../scripts/mmd2odf' -y MMD2ODF.app


