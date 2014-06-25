//
// Copyleft RIME Developers
// License GPLv3
//
// 2014-06-25 GONG Chen <chen.sst@gmail.com>
//

#ifndef RIME_STRING_TABLE_H_
#define RIME_STRING_TABLE_H_

#include <string>
#include <utility>
#include <vector>
#include <marisa.h>
#include <rime/common.h>

namespace rime {

using StringId = marisa::UInt32;

class StringTable {
 public:
  bool HasKey(const std::string& key);
  void CommonPrefixMatch(const std::string& query,
                         std::vector<StringId>* result);
  void PredictiveSearch(const std::string& query,
                        std::vector<StringId>* result);
  std::string GetString(StringId string_id);

 protected:
  marisa::Trie trie_;
};

class StringTableBuilder: MarisaTable {
 public:
  void Add(const std::string& key, double weight = 1.0,
           StringId* reference = nullptr);
  void Clear();

  bool Build();
  void UpdateReferences();

 private:
  marisa::Keyset keys_;
  std::vector<StringId*> references_;
};

}  // namespace rime

#endif  // RIME_STRING_TABLE_H_
