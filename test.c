typedef struct PC{
int x;
int y;
}PC;

typedef struct NPC{
uint_t character;
int x;
int y;
int ifPCseen;
int PCx;
int PCy;
}NPC;

typedef struct player_node{
int ifPC;
PC* pc;
NPC* npc;
int next_turn;
int when_initiated;
int alive;
struct player_node* prev;
struct player_node* next;
int speed;

}player_node;


typedef struct player_node_heap {
	player_node* head;
	player_node* tail;
	int size;
} node_heap;

player_node *player_grid[][];

int next_move(player_node *pn)
{
	if (pn->ifPC) return 0;
	//now we've established that the node is not of PC
	int character = pn->npc->character;
	int x = pn->npc->x;
	int y = pn->npc->y;
	neighbours* n;
	n = malloc(sizeof(neighbours))
	getneighbouts(n, x, y);
	dijik(x,y);
	int nextx;
	int nexty;
	if (character & 0xf)//assuming digger, tele, intel, non-erratic
	{
		for (int i = 0; i < n->size; i++)
		{
			if (digger_struct_low_cost[n->data[i][0]][n->data[i][1]]< least)
			{
				least = digger_struct_low_cost[n->data[i][0]][n->data[i][1]];
				nextx = ;
				nexty = ;
			}
		}
	}



	if erratic()
	{
		if (rand()& 0x1)
		{
			int selector = rand() % (n->size);
			nextx = ;
			nexty = ;
		}
	}


		digger_struct_low_cost[pn->x][pn->y];


	}



	free (n);
}

int if_in_room()
{

}

int push(node_player_heap* nh, int x, int y)
{

}
int pop(player_node_heap* nh)
{
	player_node* p = nh->head;
	int min_turn = p->next_turn;
	int min_when_initiated = p->when_initiated;
	player_node* min_node = p
	p = p->next;
	while(p!=NULL)
	{
		if ((p->next_turn) < min_turn)
		{
			min_node = p;
			min_when_initiated = p->when_initiated;
			min_turn = p->next_turn;
		}
		else if((p->next_turn) == min_turn)
		{
			if ((p->when_initiated) < min_when_initiated)
			{
				min_node = p;
				min_when_initiated = p->when_initiated;
			}
		}
	}
	//if p->ifpc then print dungeon
	next_turn(p);

}
int screen_player_heap(player_node_heap* nh){
	player_node* p = nh->head;
	while(p!=NULL)
	{
		if (!(p->alive))
		{
			kill_player(p);
			nh->size--;

		}
	}
}
int kill_player(player_node* p)
{
	//player_node* previous =
	if ((p->prev)!=NULL)
	p->prev->next = p->next;
	if ((p->next)!=NULL)
	p->next->prev = p->prev;

	if (p->ifPC)
	{
		int tempx = p->pc->x;
		int tempy = p->pc->y;
		free(p->pc);
		free(p);
		grid[tempx][tempy] = NULL;
	}
	else
	{
		int tempx = p->npc->x;
		int tempy = p->npc->y;
		free(p->npc);
		free(p);
		grid[tempx][tempy] = NULL;
	}
}


int populate_heap()
{

}


int initialize_pc()
{
	PC *pc = malloc(sizeof(PC));
	int i, j, k
	i= 1;
	while (i)
	{
		j = rand()%ylenMax;
		k = rand()%xlenMax;

		if (grid[j][k] == '.') i = 0;


	}
	pc->y = j;
	pc->x = k;

	pcx,y = randomly where char[][]  == '.';


	player_node* pn = malloc(sizeof(player_node));
	pn->ifPC = 1;
	pn->alive = 1;
	pn->pc = pc;
	pn->next_turn = 0;
	pn->when_initiated = cunter++;
	pn->speed = 10;
	grid_players[k][j] = pn;
}

int distant_from_pc(PC* p, int x, int y){
	int PCx,PCy;
	PCx = p->x;
	PCy=p->y;
	if ((x > (PCx+4))||(x < (PCx-4))) return 1;
	if ((y > (PCy+4))||(y < (PCy-4))) return 1;
	return 0;
}


int initialize_players(int n)
{
	int i, j, k , t;
	//we're assuming PC initialisation happens before other grid_players
	PC* p;
	for (i = 0; i < ylenMax; i++)
	{
		for (j = 0; j < xlenMax; j++)
		{
			if (player_grid[j][i]!=NULL){
				if (player_grid[j][i]->ifPC) p=player_grid[j][i]->pc;
			}
		}
	}


	//for () for() look for p

	for (t = 0; t < n; t++)
	{

		NPC *npc = malloc(sizeof(NPC));
		pcx,y = randomly where char[][]  == '.' and no other players initialized;


		i= 1;
		while (i)
		{
			j = rand()%ylenMax;
			k = rand()%xlenMax;

			if (grid[j][k] == '.' && grid_players[j][k]==NULL && distant_from_pc(pc, j, k)) i = 0;


		}
		pc->y = k;
		pc->x = j;


		npc->character = rand()&0xf;
		npc-> ifPCseen = 0;


		player_node* pn = malloc(sizeof(player_node));
		pn->ifPC = 0;
		pn->alive = 1;
		pn->npc = npc;
		pn->next_turn = 0;
		pn->when_initiated = cunter++;
		pn->->speed = 5+ (rand()&0xf);
		grid_players[k][j] = pn;

	}


}


/* The print_dungeon method below simply takes the x and y coordinates of the PC to make sure the @ is at the right position*/
int print_dungeon(int x, int y)
{
	int i, j;
	//for (i = 0; i < xlenMax; i++) {printf("-");}
	//printf("\n");

	for (i = 0; i < ylenMax; i++)
	{
		//printf("|");
		for (j = 0; j < xlenMax; j++)
		{

			if (grid_players[j][i]==NULL) printf("%c", grid[j][i]);
			else
			{
				if (grid_players[j][i]->ifPC) printf("@");
				else{
					printf("%x",(grid_players[j][i]->npc->character));
				}
			}
		}
		printf("\n");
	}

	//for (i = 0; i < xlenMax; i++) {printf("-");}
	//printf("\n\n\n");
}
int kill_all()
{
		for (i = 0; i < ylenMax; i++)
	{
		for (j = 0; j < xlenMax; j++)
		{
			if (grid_players[j][i]!=NULL)
			{
				if (grid_players[j][i]->ifPC)
				{
					int tempx = grid_players[j][i]->pc->x;
					int tempy = grid[j][i]->pc->y;
					free(grid[j][i]->pc);
					free(grid[j][i]);
					grid[tempx][tempy] = NULL;
				}
				else
				{
					int tempx = grid_players[j][i]->npc->x;
					int tempy = grid[j][i]->npc->y;
					free(grid[j][i]->npc);
					free(grid[j][i]);
					grid[tempx][tempy] = NULL;
				}
			}
		}
	}

}
