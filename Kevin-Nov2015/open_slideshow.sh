#/bin/bash
ipython nbconvert DistributingCode.ipynb --to slides --post serve --reveal-prefix "http://cdn.jsdelivr.net/reveal.js/2.6.2"
