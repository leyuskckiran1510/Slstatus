/* See LICENSE file for copyright and license details. */
#include <stdio.h>
#include <string.h>

#include "../util.h"

const char *
run_command(const char *cmd)
{
	char *p,temp[1024],code[350]="";//,str_perc[15];
	FILE *fp;
	int int_perc;
	if (!(fp = popen(cmd, "r"))) {
		warn("popen '%s':", cmd);
		return NULL;
	}
	p = fgets(buf, sizeof(buf) - 1, fp);
	if (pclose(fp) < 0) {
		warn("pclose '%s':", cmd);
		return NULL;
	}
	if (!p) {
		return NULL;
	}
	if ((p = strrchr(buf, '\n'))) {
		p[0] = '\0';
	}
	strcat(code,"dunstify 'Vlomue Changed' '");
	sscanf(buf,"%d%%",&int_perc);
	for(int i=0;i<int_perc/2;i++){
		strcat(code,"▓");
	}
	strcat(code,"' -t 1500 -u low -r 147987 -i ~/Suckless_Addons/Slstatus/icons/sound.png");
	//puts(code);
	//puts("\n");
	if (!strcmp("amixer sget Master | awk -F\"[][]\" '/%/ { print $2 }' | head -n1",cmd) && strcmp(temp,buf)){
		fp = popen(code,"r");//popen("notify-send  'Vloume' 'Charge Now' -u normal -t 500", "r");
		fclose(fp);
		strcpy(temp,buf);
	}

	return buf[0] ? buf : NULL;
}
