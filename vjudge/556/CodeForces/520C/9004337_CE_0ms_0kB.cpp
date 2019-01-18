                if(960-270<=T&&T<=1080-270)
                {
                        bool flag2 = false;
                        for (int k = 1; k <= ans2; k++)
                        {
                            if (buss2[k].start <= bus[i].start && buss2[k].num < 5)
                            {
                                flag2 = true;
                                buss2[k].num++;
                                buss2[k].bus[buss2[k].num].start = bus[i].start;
                                buss2[k].bus[buss2[k].num].end = bus[i].end;
                                buss2[k].start = bus[i].end + 10;
                                break;
                            }
                        }
                        if (flag2) continue;
                }
                for (int j = ans; j >= 1; j--)
                {
                    if (buss[j].start <= bus[i].start && buss[j].num < 10)   //双班车中找到可发车的
                    {
                        flag = true;
                        buss[j].num++;
                        buss[j].bus[buss[j].num].start = bus[i].start;
                        buss[j].bus[buss[j].num].end = bus[i].end;
                        buss[j].start = bus[i].end + 10;
                        if ((480-270 <= bus[i].end) && (bus[i].end <= 600-270) && (!buss[j].z))
                        {
                            buss[j].z = true;
                            buss[j].start += 10;
                            if (buss[j].num == 5)
                        {
                            buss[j].start -= 10;
                        }
                        }
                        if ((1080-270 <= bus[i].end) && (bus[i].end <= 1200-270) && (!buss[j].w))
                        {
                            buss[j].w = true;
                            buss[j].start += 10;
                            if (buss[j].num == 5)
                        {
                            buss[j].start -= 10;
                        }
                        }

                        if (buss[j].num == 5)
                        {
                            buss[j].start += 10;
                        }
                        break;
                    }
                }

                if (!flag)          //都不可发车
                {
                    if (ans < 19)   //判断应该发单班还是双班
                    {
                        ans++;
                        buss[ans].num++;
                        buss[ans].bus[buss[ans].num].start = bus[i].start;
                        buss[ans].bus[buss[ans].num].end = bus[i].end;
                        buss[ans].start = bus[i].end + 10;
                        if ((480-270 <= bus[i].end) && (bus[i].end <= 600-270) && (!buss[ans].z))
                        {
                            buss[ans].z = true;
                            buss[ans].start += 10;
                        }
                        if ((1080-270 <= bus[i].end) && (bus[i].end <= 1200-270) && (!buss[ans].w))
                        {
                            buss[ans].w = true;
                            buss[ans].start += 10;
                        }
                    }
                    else    //单班车
                    {
                        bool flag2 = false;
                        for (int k = 1; k <= ans2; k++)
                        {
                            if (buss2[k].start <= bus[i].start && buss2[k].num < 5)
                            {
                                flag2 = true;
                                buss2[k].num++;
                                buss2[k].bus[buss2[k].num].start = bus[i].start;
                                buss2[k].bus[buss2[k].num].end = bus[i].end;
                                buss2[k].start = bus[i].end + 10;
                                break;
                            }
                        }
                        if (!flag2)
                        {
                            ans2++;
                            buss2[ans2].num++;
                            buss2[ans2].bus[buss2[ans2].num].start = bus[i].start;
                            buss2[ans2].bus[buss2[ans2].num].end = bus[i].end;
                            buss2[ans2].start = bus[i].end + 10;
                        }
                    }
                }
            }
        }

        T += 0.5;
    }
    long long fuck=0;
    for (int i = 1; i <= ans; i++)
    {
        for (int j = 1; j <= buss[i].num; j++)
        {
            out(buss[i].bus[j].start);
            out(buss[i].bus[j].end);
            fuck++;
            cout << "\n";
        }
        cout << "\n"
             << "----------"
             << "\n";
    }
    cout << "\nQWERTYUIOPWERTYUIERTYUI\n";
    for (int i = 1; i <= ans2; i++)
    {
        for (int j = 1; j <= buss2[i].num; j++)
        {
            out(buss2[i].bus[j].start);
            out(buss2[i].bus[j].end);
            fuck++;
            cout << "\n";
        }
        cout << "\n"
             << "----------"
             << "\n";
    }
    cout<<fuck;
    return 0;
}