#!/bin/bash

# ============================================================
#   PUSH_SWAP TESTER - Kapsamlı Değerlendirme Scripti
# ============================================================

# ---- Renkler ----
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
MAGENTA='\033[0;35m'
BOLD='\033[1m'
RESET='\033[0m'

# ---- Sayaçlar ----
PASS=0
FAIL=0
SKIP=0

# ---- Yardımcı Fonksiyonlar ----
print_header() {
    echo ""
    echo -e "${BOLD}${BLUE}╔══════════════════════════════════════════════════════════════╗${RESET}"
    echo -e "${BOLD}${BLUE}║${RESET}  ${BOLD}$1${RESET}"
    echo -e "${BOLD}${BLUE}╚══════════════════════════════════════════════════════════════╝${RESET}"
}

print_section() {
    echo ""
    echo -e "${BOLD}${CYAN}──────────────────────────────────────────${RESET}"
    echo -e "${BOLD}${CYAN}  $1${RESET}"
    echo -e "${BOLD}${CYAN}──────────────────────────────────────────${RESET}"
}

ok() {
    echo -e "  ${GREEN}[PASS]${RESET} $1"
    ((PASS++))
}

fail() {
    echo -e "  ${RED}[FAIL]${RESET} $1"
    ((FAIL++))
}

info() {
    echo -e "  ${YELLOW}[INFO]${RESET} $1"
}

skip_test() {
    echo -e "  ${MAGENTA}[SKIP]${RESET} $1"
    ((SKIP++))
}

check_ops() {
    local ops=$1
    local excellent=$2
    local good=$3
    local acceptable=$4
    local label=$5

    if [ "$ops" -le "$excellent" ]; then
        echo -e "  ${GREEN}[PASS]${RESET} $label: ${BOLD}$ops${RESET} işlem ${GREEN}(mükemmel ≤$excellent)${RESET}"
        ((PASS++))
    elif [ "$ops" -le "$good" ]; then
        echo -e "  ${GREEN}[PASS]${RESET} $label: ${BOLD}$ops${RESET} işlem ${CYAN}(iyi ≤$good)${RESET}"
        ((PASS++))
    elif [ "$ops" -le "$acceptable" ]; then
        echo -e "  ${YELLOW}[PASS]${RESET} $label: ${BOLD}$ops${RESET} işlem ${YELLOW}(kabul edilebilir ≤$acceptable)${RESET}"
        ((PASS++))
    else
        echo -e "  ${RED}[FAIL]${RESET} $label: ${BOLD}$ops${RESET} işlem ${RED}(limit aşıldı >$acceptable)${RESET}"
        ((FAIL++))
    fi
}

# ============================================================
# ORTAM KONTROLÜ
# ============================================================
print_header "PUSH_SWAP TAM DEĞERLENDIRME TESTERİ"
echo -e "  Tarih: $(date)"
echo -e "  Dizin: $(pwd)"

# push_swap varlığı
if [ ! -f "./push_swap" ]; then
    echo -e "\n${RED}${BOLD}[HATA]${RESET} './push_swap' bulunamadı!"
    echo -e "  Lütfen bu scripti push_swap dizininde çalıştır."
    echo -e "  İpucu: önce 'make' komutunu çalıştır.\n"
    exit 1
fi

# checker varlığı
CHECKER=""
if [ -f "./checker_linux" ]; then
    CHECKER="./checker_linux"
    chmod +x ./checker_linux 2>/dev/null
    info "checker_linux bulundu."
elif [ -f "./checker_Mac" ]; then
    CHECKER="./checker_Mac"
    chmod +x ./checker_Mac 2>/dev/null
    info "checker_Mac bulundu."
else
    info "Checker bulunamadı - bazı testler atlanacak."
    info "checker_linux veya checker_Mac dosyasını bu dizine koy."
fi

# ============================================================
# 1. MAKEFILE TESTLERİ
# ============================================================
print_section "1. MAKEFILE TESTLERİ"

if [ -f "./Makefile" ]; then
    ok "Makefile mevcut"
    
    # Gerekli kurallar
    for rule in NAME all clean fclean re; do
        if grep -q "^$rule" ./Makefile || grep -q "^$rule:" ./Makefile; then
            ok "Kural bulundu: $rule"
        else
            fail "Kural eksik: $rule"
        fi
    done

    # Derleme bayrakları
    if grep -q "\-Wall" ./Makefile && grep -q "\-Wextra" ./Makefile && grep -q "\-Werror" ./Makefile; then
        ok "Derleme bayrakları: -Wall -Wextra -Werror mevcut"
    else
        fail "Derleme bayrakları eksik (gerekli: -Wall -Wextra -Werror)"
    fi

    # make clean testi
    make clean > /dev/null 2>&1
    make fclean > /dev/null 2>&1
    info "make fclean çalıştırıldı."

    # make ile derleme
    make > /dev/null 2>&1
    if [ -f "./push_swap" ]; then
        ok "make → push_swap oluşturuldu"
    else
        fail "make sonrası push_swap oluşturulamadı"
    fi

    # relink testi
    FIRST_BUILD=$(make 2>&1)
    if echo "$FIRST_BUILD" | grep -qE "cc|gcc|clang"; then
        fail "Relink tespit edildi! (make iki kez çalıştırıldı, ikincide hâlâ derleme var)"
    else
        ok "Relink yok (ikinci make derleme yapmıyor)"
    fi

    # fclean sonrası dosya kalmamalı
    make fclean > /dev/null 2>&1
    if [ ! -f "./push_swap" ]; then
        ok "make fclean → push_swap silindi"
    else
        fail "make fclean sonrası push_swap hâlâ var"
    fi

    # re testi
    make re > /dev/null 2>&1
    if [ -f "./push_swap" ]; then
        ok "make re → push_swap yeniden oluşturuldu"
    else
        fail "make re sonrası push_swap oluşturulamadı"
    fi
else
    fail "Makefile bulunamadı!"
fi

# ============================================================
# 2. HATA YÖNETİMİ
# ============================================================
print_section "2. HATA YÖNETİMİ"

# Non-numeric argüman
OUTPUT=$(./push_swap abc 2>&1 >/dev/null)
if echo "$OUTPUT" | grep -q "^Error$"; then
    ok "Non-numeric argüman → 'Error' (stderr)"
else
    fail "Non-numeric argüman → beklenen 'Error', alınan: '$OUTPUT'"
fi

# Duplicate argüman
OUTPUT=$(./push_swap 1 2 3 2 2>&1 >/dev/null)
if echo "$OUTPUT" | grep -q "^Error$"; then
    ok "Duplicate argüman → 'Error' (stderr)"
else
    fail "Duplicate argüman → beklenen 'Error', alınan: '$OUTPUT'"
fi

# MAXINT aşımı
OUTPUT=$(./push_swap 1 2147483648 3 2>&1 >/dev/null)
if echo "$OUTPUT" | grep -q "^Error$"; then
    ok "MAXINT aşımı → 'Error' (stderr)"
else
    fail "MAXINT aşımı → beklenen 'Error', alınan: '$OUTPUT'"
fi

# Parametresiz çalışma
OUTPUT=$(./push_swap 2>&1)
if [ -z "$OUTPUT" ]; then
    ok "Parametresiz → boş çıktı (doğru)"
else
    fail "Parametresiz → beklenmedik çıktı: '$OUTPUT'"
fi

# ============================================================
# 3. STRATEJİ BAYRAKLARI
# ============================================================
print_section "3. STRATEJİ SEÇIMI BAYRAKLARI"

for flag in --simple --medium --complex --adaptive; do
    OUTPUT=$(./push_swap $flag 5 4 3 2 1 2>/dev/null)
    if [ $? -eq 0 ] && [ -n "$OUTPUT" ]; then
        OPS=$(echo "$OUTPUT" | wc -l | tr -d ' ')
        ok "Flag $flag çalışıyor ($OPS işlem üretildi)"
    else
        # Bayrak yoksa veya hata veriyorsa sessizce hata say
        OUTPUT2=$(./push_swap $flag 5 4 3 2 1 2>&1)
        if echo "$OUTPUT2" | grep -qiE "unknown|invalid|error|flag"; then
            fail "Flag $flag desteklenmiyor veya hata veriyor"
        else
            fail "Flag $flag → çıktı yok veya hata"
        fi
    fi
done

# Bayragsız çalışma (--adaptive gibi davranmalı)
OUTPUT=$(./push_swap 5 4 3 2 1 2>/dev/null)
if [ -n "$OUTPUT" ]; then
    ok "Bayrak olmadan çalışıyor (varsayılan = adaptive)"
else
    fail "Bayrak olmadan çıktı yok"
fi

# ============================================================
# 4. IDENTITY TESTLERİ (Sıralı girdi)
# ============================================================
print_section "4. IDENTITY TESTLERİ (Sıralı Girdi)"

run_identity_test() {
    local input="$1"
    local label="$2"
    local output
    output=$(./push_swap $input 2>/dev/null)
    if [ -z "$output" ]; then
        ok "$label → boş çıktı (doğru, zaten sıralı)"
    else
        OPS=$(echo "$output" | wc -l | tr -d ' ')
        fail "$label → $OPS işlem üretildi (sıralı girdi için 0 beklenir)"
    fi
}

run_identity_test "42" "Tek eleman: 42"
run_identity_test "2 3" "İki eleman: 2 3"
run_identity_test "0 1 2 3" "Dört eleman: 0 1 2 3"
run_identity_test "0 1 2 3 4 5 6 7 8 9" "On eleman: 0-9"

# ============================================================
# 5. KÜÇÜK GİRDİ TESTLERİ (3 sayı)
# ============================================================
print_section "5. KÜÇÜK GİRDİ TESTLERİ (3 Sayı)"

run_small_test() {
    local args="$1"
    local label="$2"
    local output ops result

    output=$(./push_swap $args 2>/dev/null)
    ops=$(echo "$output" | grep -c '[a-z]' 2>/dev/null || echo 0)
    [ -z "$output" ] && ops=0

    if [ -n "$CHECKER" ]; then
        result=$(echo "$output" | $CHECKER $args 2>/dev/null)
        if [ "$result" = "OK" ]; then
            check_ops "$ops" 3 4 5 "$label"
        else
            fail "$label → checker: $result"
        fi
    else
        skip_test "$label → checker yok, sadece işlem sayısı: $ops"
    fi
}

run_small_test "2 1 0" "3 sayı: 2 1 0"
run_small_test "0 2 1" "3 sayı: 0 2 1"
run_small_test "1 0 2" "3 sayı: 1 0 2"

# ============================================================
# 6. ORTA GİRDİ TESTLERİ (5 sayı)
# ============================================================
print_section "6. ORTA GİRDİ TESTLERİ (5 Sayı)"

run_medium_test() {
    local args="$1"
    local label="$2"
    local output ops result

    output=$(./push_swap $args 2>/dev/null)
    ops=$(echo "$output" | grep -c '[a-z]' 2>/dev/null || echo 0)
    [ -z "$output" ] && ops=0

    if [ -n "$CHECKER" ]; then
        result=$(echo "$output" | $CHECKER $args 2>/dev/null)
        if [ "$result" = "OK" ]; then
            check_ops "$ops" 12 13 15 "$label"
        else
            fail "$label → checker: $result"
        fi
    else
        skip_test "$label → checker yok, işlem sayısı: $ops"
    fi
}

run_medium_test "1 5 2 4 3" "5 sayı: 1 5 2 4 3"
run_medium_test "5 1 4 2 3" "5 sayı: 5 1 4 2 3"
run_medium_test "3 5 1 4 2" "5 sayı: 3 5 1 4 2"

# ============================================================
# 7. BENCHMARK MODU
# ============================================================
print_section "7. BENCHMARK MODU"

BENCH_OUT=$(./push_swap --bench --simple 5 4 3 2 1 2>/dev/null)
if [ -n "$BENCH_OUT" ]; then
    ok "--bench --simple → stdout'a sıralama işlemleri üretildi"
else
    fail "--bench --simple → çıktı yok"
fi

BENCH_STDERR=$(./push_swap --bench --simple 5 4 3 2 1 2>&1 >/dev/null)
if [ -n "$BENCH_STDERR" ]; then
    ok "--bench → stderr'e benchmark bilgisi yazıldı"
    
    echo -e "  ${CYAN}--- Benchmark Çıktısı ---${RESET}"
    echo "$BENCH_STDERR" | head -20 | while IFS= read -r line; do
        echo -e "    $line"
    done
    echo -e "  ${CYAN}-------------------------${RESET}"

    # İçerik kontrolleri
    echo "$BENCH_STDERR" | grep -qi "disorder\|düzensizlik\|%" && ok "Disorder yüzdesi mevcut" || fail "Disorder yüzdesi eksik"
    echo "$BENCH_STDERR" | grep -qi "strategy\|strateji\|simple\|medium\|complex" && ok "Strateji adı mevcut" || fail "Strateji adı eksik"
    echo "$BENCH_STDERR" | grep -qi "operation\|işlem\|total\|toplam" && ok "Toplam işlem sayısı mevcut" || fail "Toplam işlem sayısı eksik"
else
    fail "--bench → stderr'e hiçbir şey yazılmadı"
fi

# Disorder hesaplama
SORTED_DISORDER=$(./push_swap --bench --simple 1 2 3 4 5 2>&1 >/dev/null | grep -oE "[0-9]+\.[0-9]+" | head -1)
if [ -n "$SORTED_DISORDER" ]; then
    # 10'dan küçükse "sıfıra yakın" kabul et
    INT_VAL=${SORTED_DISORDER%.*}
    if [ "$INT_VAL" -le 10 ] 2>/dev/null; then
        ok "Sıralı girdi disorder: %$SORTED_DISORDER (≈0 olmalı)"
    else
        fail "Sıralı girdi disorder çok yüksek: %$SORTED_DISORDER"
    fi
else
    info "Sıralı girdi disorder değeri tespit edilemedi"
fi

REV_DISORDER=$(./push_swap --bench --simple 5 4 3 2 1 2>&1 >/dev/null | grep -oE "[0-9]+\.[0-9]+" | head -1)
if [ -n "$REV_DISORDER" ]; then
    INT_VAL=${REV_DISORDER%.*}
    if [ "$INT_VAL" -ge 80 ] 2>/dev/null; then
        ok "Ters sıralı girdi disorder: %$REV_DISORDER (≈100 olmalı)"
    else
        fail "Ters sıralı girdi disorder beklenenden düşük: %$REV_DISORDER"
    fi
else
    info "Ters sıralı girdi disorder değeri tespit edilemedi"
fi

# ============================================================
# 8. BÜYÜK GİRDİ TESTLERİ (100 Sayı)
# ============================================================
print_section "8. BÜYÜK GİRDİ TESTLERİ (100 Sayı)"

if command -v shuf > /dev/null 2>&1; then
    run_large_test() {
        local n="$1"
        local max="$2"
        local excellent="$3"
        local good="$4"
        local acceptable="$5"
        local label="$6"

        local ARG=$(shuf -i 1-$max -n $n | tr '\n' ' ')
        local output ops result

        output=$(./push_swap $ARG 2>/dev/null)
        ops=$(echo "$output" | grep -c '[a-z]' 2>/dev/null || echo 0)
        [ -z "$output" ] && ops=0

        if [ -n "$CHECKER" ]; then
            result=$(echo "$output" | $CHECKER $ARG 2>/dev/null)
            if [ "$result" = "OK" ]; then
                check_ops "$ops" "$excellent" "$good" "$acceptable" "$label"
            else
                fail "$label → checker: $result (ARG=$ARG)"
            fi
        else
            if [ "$ops" -le "$acceptable" ]; then
                ok "$label → $ops işlem (checker olmadan)"
            else
                fail "$label → $ops işlem (limit: $acceptable)"
            fi
        fi
    }

    info "100 sayı testi çalışıyor (×2)..."
    run_large_test 100 500 700 1500 2000 "100 sayı - Test 1"
    run_large_test 100 500 700 1500 2000 "100 sayı - Test 2"
    run_large_test 100 500 700 1500 2000 "100 sayı - Test 3"
else
    skip_test "shuf komutu bulunamadı, büyük testler atlandı"
fi

# ============================================================
# 9. STRATEJİ BAYRAĞI TESTLERİ (50 Sayı)
# ============================================================
print_section "9. STRATEJİ BAYRAĞI KARŞILAŞTIRMASI (50 Sayı)"

if command -v shuf > /dev/null 2>&1; then
    ARG50=$(shuf -i 1-200 -n 50 | tr '\n' ' ')
    info "Test girdisi: $ARG50"

    declare -A STRATEGY_OPS
    for flag in --simple --medium --complex --adaptive; do
        output=$(./push_swap $flag $ARG50 2>/dev/null)
        ops=$(echo "$output" | grep -c '[a-z]' 2>/dev/null || echo 0)
        [ -z "$output" ] && ops=0
        STRATEGY_OPS[$flag]=$ops

        if [ -n "$CHECKER" ]; then
            result=$(echo "$output" | $CHECKER $ARG50 2>/dev/null)
            if [ "$result" = "OK" ]; then
                ok "Flag $flag → $ops işlem (checker: OK)"
            else
                fail "Flag $flag → checker: $result"
            fi
        else
            if [ "$ops" -gt 0 ]; then
                ok "Flag $flag → $ops işlem (checker yok)"
            else
                fail "Flag $flag → çıktı yok"
            fi
        fi
    done

    # Karşılaştırma tablosu
    echo ""
    echo -e "  ${BOLD}İşlem Karşılaştırması:${RESET}"
    for flag in --simple --medium --complex --adaptive; do
        printf "    %-12s : %s işlem\n" "$flag" "${STRATEGY_OPS[$flag]}"
    done

    # --complex, --simple'dan az olmalı (esneklik)
    SIMPLE_OPS=${STRATEGY_OPS[--simple]}
    COMPLEX_OPS=${STRATEGY_OPS[--complex]}
    if [ -n "$SIMPLE_OPS" ] && [ -n "$COMPLEX_OPS" ] && [ "$SIMPLE_OPS" -gt 0 ] && [ "$COMPLEX_OPS" -gt 0 ]; then
        if [ "$COMPLEX_OPS" -lt "$SIMPLE_OPS" ]; then
            ok "--complex < --simple (beklenen performans sırası)"
        else
            info "--complex ($COMPLEX_OPS) ≥ --simple ($SIMPLE_OPS) (beklenmedik, ama zorunlu değil)"
        fi
    fi
else
    skip_test "shuf bulunamadı, strateji karşılaştırması atlandı"
fi

# ============================================================
# 10. ÇOK BÜYÜK GİRDİ TESTLERİ (500 Sayı)
# ============================================================
print_section "10. ÇOK BÜYÜK GİRDİ TESTLERİ (500 Sayı)"

if command -v shuf > /dev/null 2>&1; then
    info "500 sayı testi çalışıyor (×2) - bu biraz zaman alabilir..."
    run_large_test 500 1000 5500 8000 12000 "500 sayı - Test 1"
    run_large_test 500 1000 5500 8000 12000 "500 sayı - Test 2"
else
    skip_test "shuf bulunamadı, 500 sayı testi atlandı"
fi

# ============================================================
# 11. BELLEK SIZINTISI KONTROLÜ
# ============================================================
print_section "11. BELLEK SIZINTISI (Valgrind)"

if command -v valgrind > /dev/null 2>&1; then
    VALGRIND_OUT=$(valgrind --leak-check=full --error-exitcode=1 ./push_swap 5 4 3 2 1 2>&1)
    if echo "$VALGRIND_OUT" | grep -q "no leaks are possible\|0 bytes in 0 blocks\|ERROR SUMMARY: 0"; then
        ok "Valgrind: bellek sızıntısı yok"
    elif echo "$VALGRIND_OUT" | grep -q "definitely lost: 0"; then
        ok "Valgrind: kesin sızıntı yok (minor indirectly lost kabul edilebilir)"
    else
        LEAK_LINE=$(echo "$VALGRIND_OUT" | grep "definitely lost" | head -1)
        fail "Valgrind bellek sızıntısı: $LEAK_LINE"
    fi
else
    skip_test "valgrind bulunamadı, bellek kontrolü atlandı"
fi

# ============================================================
# ÖZET RAPOR
# ============================================================
TOTAL=$((PASS + FAIL))
echo ""
echo -e "${BOLD}${BLUE}╔══════════════════════════════════════════════════════════════╗${RESET}"
echo -e "${BOLD}${BLUE}║${RESET}  ${BOLD}SONUÇ ÖZETI${RESET}"
echo -e "${BOLD}${BLUE}╠══════════════════════════════════════════════════════════════╣${RESET}"
echo -e "${BOLD}${BLUE}║${RESET}  ${GREEN}PASS : $PASS${RESET}"
echo -e "${BOLD}${BLUE}║${RESET}  ${RED}FAIL : $FAIL${RESET}"
echo -e "${BOLD}${BLUE}║${RESET}  ${MAGENTA}SKIP : $SKIP${RESET}"
echo -e "${BOLD}${BLUE}║${RESET}  ${BOLD}TOPLAM: $TOTAL (skip hariç)${RESET}"
if [ "$TOTAL" -gt 0 ]; then
    PERCENT=$(( PASS * 100 / TOTAL ))
    echo -e "${BOLD}${BLUE}║${RESET}  ${BOLD}BAŞARI: %$PERCENT${RESET}"
fi
echo -e "${BOLD}${BLUE}╚══════════════════════════════════════════════════════════════╝${RESET}"
echo ""

if [ "$FAIL" -eq 0 ]; then
    echo -e "${GREEN}${BOLD}  Tebrikler! Tüm testler geçti.${RESET}"
elif [ "$FAIL" -le 3 ]; then
    echo -e "${YELLOW}${BOLD}  Çoğu test geçti. Küçük sorunlar var.${RESET}"
else
    echo -e "${RED}${BOLD}  Birçok test başarısız. Gözden geçir.${RESET}"
fi
echo ""
