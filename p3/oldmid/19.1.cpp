void dr(char* s, clist* l)
{
  cnode* trav = l->head;
  stack st;
  st.push(trav);
  for(int i = 0; s[i] != '\0'; i++)
  {
    if(s[i] == 'U'){
      trav = trav->up;
      st.push(trav);
    }
    if(s[i] == 'R')
    {
      trav = trav->next;
      st.push(trav);
    }
  }
}