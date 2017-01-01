#
# Regular cron jobs for the pthread-embedded package
#
0 4	* * *	root	[ -x /usr/bin/pthread-embedded_maintenance ] && /usr/bin/pthread-embedded_maintenance
