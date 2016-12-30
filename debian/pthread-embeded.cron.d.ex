#
# Regular cron jobs for the pthread-embeded package
#
0 4	* * *	root	[ -x /usr/bin/pthread-embeded_maintenance ] && /usr/bin/pthread-embeded_maintenance
