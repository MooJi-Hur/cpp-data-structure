### Map 입출력
- 입력
```c++
    for (auto &myWordrobe : myWordrobes)
    {
        int attributeCount;
        cin >> attributeCount;

        for (int i = 0; i < attributeCount; ++i)
        {
            string attribute, category;
            cin >> attribute >> category;

            myWordrobe[category].push_back(attribute);
        }
    }
```

- 출력
```c++
    for (auto &myWordrobe : myWordrobes)
    {

        for (auto &[category, attributes] : myWordrobe)
        {
            cout << category << " : ";
            for (auto &attribute : attributes)
            {
                cout << attribute << ' ';
            }
            cout << '\n';
        }

        cout << '\n';
    }
```