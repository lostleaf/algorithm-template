for(i=1;i<=n;rec[++cnt]=dat[i++])
	for(j=cnt;j>0;j--)
		if(jiao(dat[i],rec[j]))
		{
			if(dat[i].x1>rec[j].x1&&dat[i].x1<rec[j].x2)
				rec[++cnt]=rec[j],rec[cnt].x2=dat[i].x1,rec[j].x1=dat[i].x1;
			if(dat[i].x2<rec[j].x2&&dat[i].x2>rec[j].x1)
				rec[++cnt]=rec[j],rec[cnt].x1=dat[i].x2,rec[j].x2=dat[i].x2;
			if(dat[i].y1>rec[j].y1&&dat[i].y1<rec[j].y2)
				rec[++cnt]=rec[j],rec[cnt].y2=dat[i].y1,rec[j].y1=dat[i].y1;
			if(dat[i].y2<rec[j].y2&&dat[i].y2>rec[j].y1)
				rec[++cnt]=rec[j],rec[cnt].y1=dat[i].y2,rec[j].y2=dat[i].y2;
			swap(rec[j],rec[cnt--]);
		}