class CAccessory
{
private:
	char Type;
	int Size;
public:
	CAccessory()
	{
		Type = ' ';
		Size = 0;
	}

	CAccessory(char t , int s)
	{
		Type = t;
		Size = s;
	}

	void SetType(char val)
	{
		if (val >= 'A' && val <= 'C')
			Type = val;
	}

	void SetSize(int val)
	{
		if (val > 0)
			Size = val;
	}

	char GetType()
	{
		return Type;
	}

	int GetSize()
	{
		return Size;
	}
	
	int CalcCost()
	{
		int prc = 0;
		if (Type == 'A')
			prc = 20;
		if (Type == 'B')
			prc = 30;
		if (Type == 'C')
			prc = 40;

		int cst = Size * prc;
		return cst;
	}
};

class LeatherSpace
{
private:
	char Color;
	int  Wd;
	int  Ht;
public:
	LeatherSpace()
	{
		Color = ' ';
		Wd = 0;
		Ht = 0;


	}

	LeatherSpace(char c , int w, int h)
	{
		Color = c;
		Wd = w;
		Ht = h;
	}

	void SetColor(char val)
	{
		if (val == 'R' || val == 'W' || val == 'B')
		{
			Color = val;
		}
	}

	void SetWidth(int val)
	{
		if (val > 0)
			Wd = val;
	}

	void SetHeight(int val)
	{
		if (val > 0)
			Ht = val;
	}

	char GetColor() { return Color; }
	int GetWidth() { return Wd; }
	int GetHeight() { return Ht; }


	int CalcCost()
	{
		int prc;
		if (Color == 'R') prc = 50;
		if (Color == 'B') prc = 60;
		if (Color == 'W') prc = 70;

		int cst = Wd * Ht * prc;
		return cst;
	}

	int isMatched( LeatherSpace anth)
	{
		if (   (Color == 'W' || anth.Color == 'W')
			|| (Color ==  anth.Color)
			)
			return 1;
		else
			return 0;
	}
};

class HandBag
{
private:
	char BName;
	int  NumAcc;
	CAccessory* pAcc;
	int  NumLes;
	LeatherSpace* pLas;

public:
	HandBag()
	{
		BName  = '\0';
		NumAcc = 0;
		pAcc   = nullptr;
		NumLes = 0;
		pLas   = nullptr;
	}
	HandBag(char nm , int n1, CAccessory *p1 , int n2 ,LeatherSpace *p2)
	{
		BName  = nm;
		NumAcc = n1;
		pAcc = new CAccessory[NumAcc];
		for (int i = 0; i < NumAcc; i++)
		{
			pAcc[i] = p1[i];
		}
		NumLes = n2;
		pLas = new LeatherSpace[NumLes];
		for (int i = 0; i < NumLes; i++)
		{
			pLas[i] = p2[i];
		}
	}
	HandBag(HandBag &S)
	{
		BName = S.BName;
		NumAcc = S.NumAcc;
		pAcc = new CAccessory[NumAcc];
		for (int i = 0; i < NumAcc; i++)
		{
			pAcc[i] = S.pAcc[i];
		}
		NumLes = S.NumLes;
		pLas = new LeatherSpace[NumLes];
		for (int i = 0; i < NumLes; i++)
		{
			pLas[i] = S.pLas[i];
		}
	}

	void operator=(HandBag S)
	{
		BName = S.BName;
		NumAcc = S.NumAcc;
		pAcc = new CAccessory[NumAcc];
		for (int i = 0; i < NumAcc; i++)
		{
			pAcc[i] = S.pAcc[i];
		}
		NumLes = S.NumLes;
		pLas = new LeatherSpace[NumLes];
		for (int i = 0; i < NumLes; i++)
		{
			pLas[i] = S.pLas[i];
		}
	}

	~HandBag()
	{
		delete[]pAcc;
		delete[]pLas;
	}

	void SetBName(char val)
	{
		BName = val;
	}
	char GetBName() { return BName; };

	void SetNumAcc(int val)
	{
		if (val > 0)
		{
			NumAcc = val;
			pAcc = new CAccessory[NumAcc];
		}
	}

	int GetNumAcc() { return NumAcc; };

	void SetNumLeas(int val)
	{
		if (val > 0)
		{
			NumLes = val;
			pLas = new LeatherSpace[NumLes];
		}
	}

	int GetNumLeas() { return NumLes; };

	void SetSingleAcc(CAccessory val, int i)
	{
		if (i >= 0 && i < NumAcc)
		{
			pAcc[i] = val;
		}
	}

	CAccessory GetSingleAcc(int i) { return pAcc[i]; };

	void SetSingleLeas(LeatherSpace val, int i)
	{
		if (i >= 0 && i < NumLes)
		{
			pLas[i] = val;
		}
	}

	LeatherSpace GetSingleLas(int i) { return pLas[i]; };


	int CalcCost()
	{
		int tot = 0;
		for (int i = 0; i < NumAcc; i++)
		{
			tot += pAcc[i].CalcCost();
		}

		for (int i = 0; i < NumLes; i++)
		{
			tot += pLas[i].CalcCost();
		}
		return tot;
	}

	int isThereConflictInDesign()
	{
		int ctConflict = 0;
		for (int i = 0; i < NumLes; i++)
		{
			LeatherSpace Li = pLas[i];
			for (int k = 0; k < NumLes; k++)
			{
					LeatherSpace Lk = pLas[k];
					int res = Li.isMatched(Lk);
					if (res == 0)
					{
						ctConflict++;
					}
			}
		}
		return ctConflict;
	}
};

class Shop
{
private:
	char Name;

	int NumH;
	HandBag* pHbgs;

public:
	Shop()
	{
		Name = ' ';
		NumH = 0;
		pHbgs = nullptr;
	}
	Shop(char nm , int n , HandBag *p)
	{
		Name = nm;
		NumH = n;
		pHbgs = new HandBag[NumH];
		for (int i = 0; i < NumH; i++)
		{
			pHbgs[i] = p[i];
		}
	}
	Shop(Shop &S)
	{
		Name = S.Name;
		NumH = S.NumH;
		pHbgs = new HandBag[NumH];
		for (int i = 0; i < NumH; i++)
		{
			pHbgs[i] = S.pHbgs[i];
		}
	}
	void operator=(Shop& S)
	{
		Name = S.Name;
		NumH = S.NumH;
		pHbgs = new HandBag[NumH];
		for (int i = 0; i < NumH; i++)
		{
			pHbgs[i] = S.pHbgs[i];
		}
	}

	~Shop()
	{
		delete[]pHbgs;
	}


	void SetName(char val)
	{
		Name = val;
	}

	char GetName() { return Name; }

	void SetNum(int val)
	{
		if (val > 0)
		{
			NumH = val;
			pHbgs = new HandBag[NumH];
		}
	}

	int GetNum() { return NumH; }
	void SetSingleHandBg(HandBag val, int i)
	{
		if (i >= 0 && i < NumH)
		{
			pHbgs[i] = val;
		}
	}

	HandBag GetSingleHandBg(int i) { return pHbgs[i]; }


	int HowManyConflictBags()
	{
		int ct = 0; 
		for (int i = 0; i < NumH; i++)
		{
			int res  = pHbgs[i].isThereConflictInDesign();
			if (res != 0)
			{
				ct++;
			}
		}
		return ct;
	}

	void Swap(Shop anth)
	{
		int ctBad = 0;
		ctBad = HowManyConflictBags();

		HandBag* pGood = new HandBag[NumH - ctBad];
		HandBag* pAnother = new HandBag[anth.NumH + ctBad];
		int k = 0;
		for (int i = 0; i < NumH; i++)
		{
			int res = pHbgs[i].isThereConflictInDesign();
			if (res == 0)
			{
				pGood[k] = pHbgs[i];
				k++;
			}
		}
		int w = 0;
		for (int i = 0; i < anth.NumH; i++)
		{
			pAnother[w] = anth.pHbgs[i];
			w++;
		}

		for (int i = 0; i < NumH; i++)
		{
			int res = pHbgs[i].isThereConflictInDesign();
			if (res != 0)
			{
				pAnother[w] = pHbgs[i];
				w++;
			}
		}

		delete[]pHbgs;
		delete[]anth.pHbgs;

		pHbgs = pGood;
		anth.pHbgs = pAnother;
	}
};

void main()
{

}