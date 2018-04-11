shopt -s globstar

ls -R1 ./pack/**/ancient.white.*.png | sort > aw.out
ls -R1 ./pack/**/ancient.brown.*.png | sort > ab.out
ls -R1 ./pack/**/ancient.grey.*.png | sort > ag.out
ls -R1 ./pack/**/ancient.tan.*.png | sort > at.out
ls -R1 ./pack/**/ancient.*.png | sort > a.out

comm -23 a.out aw.out | comm -23 - aw.out | comm -23 - ab.out | comm -23 - ag.out |  comm -23 - at.out > rest.a.out
wc -l a.out aw.out ab.out ag.out at.out rest.a.out
cat rest.a.out
