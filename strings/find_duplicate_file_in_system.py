# 609. Find Duplicate File in System
# medium
# c++ 处理输入得半个小时...python十分钟搞定，哎

class Solution:
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """

        content_to_file = {}
        for path in paths:
            paf = path.split(' ')
            direc = paf[0]
            files = paf[1:]
            for file in files:
                file_name = file.split('(')[0]
                content = file.split('(')[1][:-1]

                val = direc + '/' + file_name
                if content in content_to_file:
                    content_to_file[content].append(val)
                else:
                    content_to_file[content] = [val]
        return [v for v in content_to_file.values() if len(v) > 1]


# ps. 别人的超简单solution
# def findDuplicate(self, paths):
#     M = collections.defaultdict(list)
#     for line in paths:
#         data = line.split()
#         root = data[0]
#         for file in data[1:]:
#             name, _, content = file.partition('(')
#             M[content[:-1]].append(root + '/' + name)
#
#     return [x for x in M.values() if len(x) > 1]

# c++
# vector<vector<string>> findDuplicate(vector<string>& paths) {
#     unordered_map<string, vector<string>> files;
#     vector<vector<string>> result;
#
#     for (auto path : paths) {
# 	    stringstream ss(path);
# 	    string root;
# 	    string s;
# 	    getline(ss, root, ' ');
# 	    while (getline(ss, s, ' ')) {
# 		    string fileName = root + '/' + s.substr(0, s.find('('));
# 		    string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
# 		    files[fileContent].push_back(fileName);
# 	    }
#     }
#
#     for (auto file : files) {
# 	    if (file.second.size() > 1)
# 		    result.push_back(file.second);
#     }
#
#     return result;
# }
