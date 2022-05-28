n, m = map(int, input().split())

teamMember = {}
memberTeam = {}
for i in range(n):
    teamName, teamLen = input(), int(input())
    teamMember[teamName] = []
    for j in range(teamLen):
        member = input()
        teamMember[teamName].append(member)
        memberTeam[member] = teamName

for i in range(m):
    key, num = input(), int(input())
    if num:
        print(memberTeam[key])
    else:
        print('\n'.join(sorted(teamMember[key])))
