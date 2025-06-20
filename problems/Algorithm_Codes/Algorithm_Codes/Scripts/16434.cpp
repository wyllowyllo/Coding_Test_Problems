#include <bits/stdc++.h>
using namespace std;

namespace My {
	//문제 범위 상 long long을 사용해야 함
	//몬스터와 싸우는 과정을 직접 구현하면 시간 초과 남
	//이분탐색 활용시 , 무엇을 lo,hi로 설정해야 할지 고민

	typedef long long ll;

	ll n;
	ll init_H, cur_H;

	ll t, a, h;
	ll ret;

	struct room {
		ll t;
		ll a;
		ll h;
	}rooms[123460];


	ll battle(ll myHP, room roomInfo) {
		ll monsterHP = roomInfo.h;

		//직접 전투과정 시뮬레이션 하니 시간초과 남...
		/*while (monsterHP>0) {
			monsterHP -= cur_H;
			if (monsterHP <= 0)break;

			curHP -= roomInfo.a;
			if (curHP <= 0) break;
		}*/

		//아래 로직으로 변경!

		//몬스터 처치 위해 필요한 공격횟수
		ll a = (monsterHP / cur_H);
		if (monsterHP % cur_H) a++;

		//몬스터가 때리는 횟수
		ll b = a - 1;

		if (myHP <= b * roomInfo.a)
			return -1; //사망

		return myHP - b * roomInfo.a;
	}
	bool check(ll maxHP) {
		ll curHP = maxHP;
		cur_H = init_H;

		for (int i = 0; i < n; i++) {
			if (rooms[i].t == 2) {
				cur_H += rooms[i].a;
				curHP = min(curHP + rooms[i].h, maxHP);
			}
			else {
				curHP = battle(curHP, rooms[i]);
				if (curHP <= 0) return false;
			}
		}

		return true;
	}


	void MySol() {
		ios::sync_with_stdio(false); cin.tie(NULL);

		cin >> n;
		cin >> init_H;

		ll lo = 1, hi = 1000000 * n * 1000000 + 1; //최대체력이 1이라도, 몬스터 원샷원킬하면 통과 가능하므로, lo는 1로 설정
		                                           //hi는 모든 방(n)에 몬스터가 있고, 모든 몬스터가 최대 체력(100만)이고, 플레이어 공격력이 1일떄를 가정

		for (int i = 0; i < n; i++) {
			cin >> t >> a >> h;
			rooms[i].t = t;
			rooms[i].a = a;
			rooms[i].h = h;

		}


		while (lo <= hi) {
			ll mid = (lo + hi) / 2;
			if (check(mid)) {
				ret = mid;
				hi = mid - 1;
			}
			else {
				lo = mid + 1;
			}
		}

		cout << ret << "\n";
	}

}

namespace Sol_1 {
	//용사가 먼저 공격하고, 이후 몬스터가 공격하는 식이기에, 몬스터의 공격 횟수는  용사의 공격 횟수-1이 될 수 밖에 없다
	//이분탐색 문제는 그냥 long long 박고 시작하자
	//int 변수 최댓값 초기화는 1e9, long long 변수 최댓값 초기화는 1e18


	typedef long long ll;
	ll n, attack, t[130005], a[130005], h[130005], lo, hi, ret;

	bool check(ll mid) {
		ll mxHP = mid;
		ll init_attack = attack;

		for (int i = 0; i < n; i++) {
			if (t[i] == 2) {
				mid = min(mxHP, mid + h[i]);
				init_attack += a[i];
			}
			else {
				//플레이어의 공격 횟수
				ll cnt = h[i] / init_attack + (h[i] % init_attack ? 1 : 0);

				mid -= (cnt - 1) * a[i]; //데미지(공격횟수*공격력) 만큼 체력 차감
			}

			if (mid <= 0) return false;
		}

		return true;
	}
	void Sol_1() {
		ios::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> n >> attack;
		for (int i = 0; i < n; i++) {
			cin >> t[i] >> a[i] >> h[i];
		}
		lo = 1, hi = 1e18 + 4;

		while (lo <= hi) {
			ll mid = (lo + hi) / 2;
			if (check(mid)) {
				hi = mid - 1;
				ret = mid;
			}
			else lo = mid + 1;
		}

		cout << ret << '\n';
	}

}

namespace Sol_2 {
	typedef long long ll;
	ll n, atk, t, a, h, H, mx, damage;

	//그리디한 풀이법
	// 매 방을 방문할 때마다 ‘지금 당장’ 필요한 최소 한계 체력만큼만 바로바로(국지적으로) 누적해서 더해 나간다
	//필요한 용사의 최대HP의 최소치는, 플레이어가 받는 모든 데미지+1 (즉 모든 방을 다 방문한 후 남은 체력이 1이면 됨)이 된다.
	//모든 방을 다 순회한 후 용사의 체력이 1이 되는 최대체력이 문제의 정답이 됨을 간파함이 중요.
	//따라서, 몬스터가 나올 때마다 그 데미지를 누적한 후, 마지막에 데미지 총합+1 = 용사 최대 체력 으로 하면 됨
	//이때 포션이 나올 경우엔, 그 다음 몬스터의 데미지는 저 포션만큼 차감되어 누적됨

	
	void Sol_2() {
		ios_base::sync_with_stdio(0); cin.tie(0);

		cin >> n >> atk;

		for (int i = 0; i < n; i++) {
			cin >> t >> a >> h;

			if (t == 1) {
				damage = a * (ceil((double)h / atk) - 1); //공격력 * 공격횟수 (이때 공격횟수는 (h/atk)+(h%atk?1:0) == ceil((double)h/atk)
				if (H < damage) {
					//이전에 먹은 포션보다 데미지가 클 경우
					mx += damage - H;//차감된 값 만큼 최대체력에 누적
					H = 0; //물약은 여기서 썼으므로 다시 0
				}
				else H -= damage; //몬스터 데미지보다 물약값이 더 크다면 최대체력에 누적하지 않고 H차감
			}
			else { //물약일 경우
				atk += a;
				H = min(H + h, mx);
			}
		}

		cout << mx + 1 << "\n";
	}
}


int main() {
	Sol_2::Sol_2();

}